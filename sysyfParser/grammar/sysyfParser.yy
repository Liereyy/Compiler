%skeleton "lalr1.cc" /* -*- c++ -*- */
%require "3.0"
%defines
//%define parser_class_name {sysyfParser}
%define api.parser.class {sysyfParser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
#include <string>
#include "SyntaxTree.h"
#include <iostream>
using namespace std;
class sysyfDriver;
}

// The parsing context.
%param { sysyfDriver& driver }

// Location tracking
%locations
%initial-action
{
// Initialize the initial location.
@$.begin.filename = @$.end.filename = &driver.file;
};

// Enable tracing and verbose errors (which may be wrong!)
%define parse.trace
%define parse.error verbose

// Parser needs to know about the driver:
%code
{
#include "sysyfDriver.h"
#define yylex driver.lexer.yylex
}

// Tokens:
%define api.token.prefix {TOK_}

%token END
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token ASSIGN SEMICOLON
%token COMMA LPARENTHESE RPARENTHESE
%token LSQUARE RSQUARE
%token LBRACE RBRACE
%token CONST
%token IF ELSE WHILE BREAK CONTINUE
%token EQ NEQ
%token LT GT LE GE
%token INT FLOAT RETURN VOID
%token <std::string>IDENTIFIER
%token <int>INTCONST
%token <double>FLOATCONST
%token EOL COMMENT
%token BLANK NOT


// Use variant-based semantic values: %type and %token expect genuine types
%type <SyntaxTree::Assembly*>CompUnit
%type <SyntaxTree::PtrList<SyntaxTree::GlobalDef>>GlobalDecl
%type <SyntaxTree::Type>BType
%type <SyntaxTree::PtrList<SyntaxTree::VarDef>>VarDecl
%type <SyntaxTree::PtrList<SyntaxTree::VarDef>>VarDefList
%type <SyntaxTree::VarDef*>VarDef
%type <SyntaxTree::InitVal*>InitVal
%type <SyntaxTree::FuncDef*>FuncDef
%type <SyntaxTree::FuncFParamList*>FuncFParamList
%type <SyntaxTree::FuncCallStmt*>FuncCall
%type <SyntaxTree::FuncParam*>FuncParam
%type <SyntaxTree::BlockStmt*>Block
%type <SyntaxTree::PtrList<SyntaxTree::Stmt>>BlockItemList
%type <SyntaxTree::PtrList<SyntaxTree::Stmt>>BlockItem
%type <SyntaxTree::Stmt*>Stmt
%type <SyntaxTree::ReturnStmt*>RetStmt
%type <SyntaxTree::IfStmt*>IfStmt
%type <SyntaxTree::WhileStmt*>WhileStmt
%type <SyntaxTree::BreakStmt*>BreakStmt
%type <SyntaxTree::ContinueStmt*>ContinueStmt
%type <SyntaxTree::LVal*>LVal
%type <SyntaxTree::Expr*>Exp
%type <SyntaxTree::Expr*>Cond
%type <SyntaxTree::Expr*>EqExp
%type <SyntaxTree::Expr*>RelExp
%type <SyntaxTree::Expr*>AddExp
%type <SyntaxTree::Expr*>MulExp
%type <SyntaxTree::Expr*>UnaryExpr
%type <SyntaxTree::Expr*>PrimaryExpr
%type <SyntaxTree::PtrList<SyntaxTree::Expr>>ExpList
%type <SyntaxTree::Literal*>Number


// No %destructors are needed, since memory will be reclaimed by the
// regular destructors.

// Grammar:
%start Begin 

%%
Begin: CompUnit END {
	$1->loc = @$;
	driver.root = $1;
	return 0;
}
;

CompUnit:CompUnit GlobalDecl{
		$1->global_defs.insert($1->global_defs.end(), $2.begin(), $2.end());
		$$=$1;
	} 
	| GlobalDecl{
		$$=new SyntaxTree::Assembly();
		$$->global_defs.insert($$->global_defs.end(), $1.begin(), $1.end());
  	}
;

GlobalDecl:FuncDef{
		$$=SyntaxTree::PtrList<SyntaxTree::GlobalDef>();
		$$.push_back(SyntaxTree::Ptr<SyntaxTree::GlobalDef>($1));
  	}
	| VarDecl{
		$$=SyntaxTree::PtrList<SyntaxTree::GlobalDef>();
		for (auto i : $1)
		{
			$$.push_back(SyntaxTree::Ptr<SyntaxTree::GlobalDef>(i));
		}
  	}
;

BType: VOID{
		$$=SyntaxTree::Type::VOID;
	}
	| INT{
		$$=SyntaxTree::Type::INT;
  	}
  	| FLOAT{
		$$=SyntaxTree::Type::FLOAT;
  	}
;

VarDecl: CONST BType VarDefList SEMICOLON{
		$$=$3;
		for (auto &node : $$) {
			node->is_constant = true;
			node->btype = $2;
		}
	}
	| BType VarDefList SEMICOLON{
		$$=$2;
		for (auto &node : $$) {
			node->btype = $1;
		}
	}
;

VarDefList:VarDefList COMMA VarDef{
		$1.push_back(SyntaxTree::Ptr<SyntaxTree::VarDef>($3));
		$$=$1;
	}
	| VarDef{
		$$=SyntaxTree::PtrList<SyntaxTree::VarDef>();
		$$.push_back(SyntaxTree::Ptr<SyntaxTree::VarDef>($1));
	}
;

VarDef:IDENTIFIER{
		$$=new SyntaxTree::VarDef();
		$$->name=$1;
		$$->is_inited = false;
		$$->loc = @$;
	}
	| IDENTIFIER LSQUARE Exp RSQUARE{
		$$=new SyntaxTree::VarDef();
		$$->name=$1;
		$$->is_inited = false;
		$$->array_length.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>($3));
		$$->loc = @$;
	}
	| IDENTIFIER ASSIGN InitVal{
		$$ = new SyntaxTree::VarDef();
		$$->name = $1;
		$$->initializers = SyntaxTree::Ptr<SyntaxTree::InitVal>($3);
		$$->is_inited = true;
		$$->loc = @$;
	}
	| IDENTIFIER LSQUARE Exp RSQUARE ASSIGN InitVal{
		$$ = new SyntaxTree::VarDef();
		$$->name = $1;
		$$->initializers = SyntaxTree::Ptr<SyntaxTree::InitVal>($6);
		$$->array_length.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>($3));
		$$->is_inited = true;
		$$->loc = @$;
	}
;

InitVal: LBRACE RBRACE{
		$$ = new SyntaxTree::InitVal();
		$$->isExp = false;
	}
	| LBRACE ExpList RBRACE{
		$$ = new SyntaxTree::InitVal();
		$$->isExp = false;
		for (auto i : $2)
		{
			auto tmp = new SyntaxTree::InitVal();
			tmp->isExp = true;
			tmp->expr = SyntaxTree::Ptr<SyntaxTree::Expr>(i);
			$$->elementList.push_back(SyntaxTree::Ptr<SyntaxTree::InitVal>(tmp));
		}
	}
	| Exp{
		$$ = new SyntaxTree::InitVal();
		$$->isExp = true;
		$$->expr = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		$$->loc = @$;
	}
;

FuncCall: IDENTIFIER LPARENTHESE ExpList RPARENTHESE {
		$$ = new SyntaxTree::FuncCallStmt();
		$$->name = $1;
		$$->params = $3;
		$$->loc = @$;
	}
	| IDENTIFIER LPARENTHESE RPARENTHESE {
		$$ = new SyntaxTree::FuncCallStmt();
		$$->name = $1;
		$$->loc = @$;
	}
;

FuncDef: BType IDENTIFIER LPARENTHESE FuncFParamList RPARENTHESE Block{
		$$ = new SyntaxTree::FuncDef();
		$$->ret_type = $1;
		$$->param_list = SyntaxTree::Ptr<SyntaxTree::FuncFParamList>($4);
		$$->name = $2;
		$$->body = SyntaxTree::Ptr<SyntaxTree::BlockStmt>($6);
		$$->loc = @$;
	}
;

FuncFParamList: FuncFParamList COMMA FuncParam{
		$1->params.push_back(SyntaxTree::Ptr<SyntaxTree::FuncParam>($3));
		$$=$1;
	}
	| FuncParam{
		$$ = new SyntaxTree::FuncFParamList();
		$$->params.push_back(SyntaxTree::Ptr<SyntaxTree::FuncParam>($1));
	}
	| %empty{
		$$ = new SyntaxTree::FuncFParamList();
	}
;

FuncParam: BType IDENTIFIER{
		$$ = new SyntaxTree::FuncParam();
		$$->name = $2;
		$$->param_type = $1;
		$$->loc = @$;
	}
;

Block:LBRACE BlockItemList RBRACE{
		$$ = new SyntaxTree::BlockStmt();
		$$->body = $2;
		$$->loc = @$;
	}
;

BlockItemList:BlockItemList BlockItem{
		$1.insert($1.end(), $2.begin(), $2.end());
		$$ = $1;
	}
	| %empty{
		$$ = SyntaxTree::PtrList<SyntaxTree::Stmt>();
	}
;

BlockItem:VarDecl{
		$$ = SyntaxTree::PtrList<SyntaxTree::Stmt>();
		$$.insert($$.end(), $1.begin(), $1.end());
	}
	| Stmt{
		$$ = SyntaxTree::PtrList<SyntaxTree::Stmt>();
		$$.push_back(SyntaxTree::Ptr<SyntaxTree::Stmt>($1));
	}
;

Stmt:LVal ASSIGN Exp SEMICOLON{
		auto temp = new SyntaxTree::AssignStmt();
		temp->target = SyntaxTree::Ptr<SyntaxTree::LVal>($1);
		temp->value = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| Exp SEMICOLON{
		auto temp = new SyntaxTree::ExprStmt();
		temp->exp = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		$$ = temp;
		$$->loc = @$;
	}
	| Block{
		$$ = $1;
	}
	| SEMICOLON{
		$$ = new SyntaxTree::EmptyStmt();
		$$->loc = @$;
	}
	| IfStmt{
		$$ = $1;
	}
	| WhileStmt{
		$$ = $1;
	}
	| BreakStmt{
		$$ = $1;
	}
	| ContinueStmt{
		$$ = $1;
	}
	| RetStmt{
		$$ = $1;
	}
;

RetStmt: RETURN Exp SEMICOLON{
		$$ = new SyntaxTree::ReturnStmt();
		$$->ret = SyntaxTree::Ptr<SyntaxTree::Expr>($2);
		$$->loc = @$;
	}
	| RETURN SEMICOLON{
		auto temp = new SyntaxTree::ReturnStmt();
		$$ = temp;
		$$->loc = @$;
	}
;

IfStmt: IF LPARENTHESE Cond RPARENTHESE Stmt ELSE Stmt{
		$$ = new SyntaxTree::IfStmt();
		$$->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$->if_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>($5);
		$$->else_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>($7);
	}
	| IF LPARENTHESE Cond RPARENTHESE Stmt{
		$$ = new SyntaxTree::IfStmt();
		$$->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$->if_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>($5);
	}
;

WhileStmt: WHILE LPARENTHESE Cond RPARENTHESE Stmt{
		$$ = new SyntaxTree::WhileStmt();
		$$->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$->statement = SyntaxTree::Ptr<SyntaxTree::Stmt>($5);
	}
;

BreakStmt: BREAK SEMICOLON{
		$$ = new SyntaxTree::BreakStmt();
	}
;

ContinueStmt: CONTINUE SEMICOLON{
		$$ = new SyntaxTree::ContinueStmt();
	}
;

ExpList: ExpList COMMA Exp{
		$1.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>($3));
		$$ = $1;
	}
	| Exp{
		$$ = SyntaxTree::PtrList<SyntaxTree::Expr>();
		$$.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>($1));
	}
;

Cond: EqExp{
		$$ = $1;
	}
;

EqExp: RelExp{
		$$ = $1;
	}
	| EqExp EQ RelExp{
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::EQ;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| EqExp NEQ RelExp{
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::NEQ;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
;

RelExp: AddExp{
		$$ = $1;
	}
	| RelExp LT AddExp {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::LT;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| RelExp GT AddExp {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::GT;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| RelExp LE AddExp {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::LTE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| RelExp GE AddExp {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::GTE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
;

Exp: AddExp{
		$$ = $1;
	}
;

AddExp: MulExp{
		$$ = $1;
	}
	| AddExp PLUS MulExp{
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::PLUS;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| AddExp MINUS MulExp{
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MINUS;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
;

MulExp: UnaryExpr{
		$$ = $1;
	}
	| MulExp MULTIPLY UnaryExpr{
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MULTIPLY;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| MulExp DIVIDE UnaryExpr{
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::DIVIDE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
	| MulExp MODULO UnaryExpr{
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MODULO;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>($1);
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($3);
		$$ = temp;
		$$->loc = @$;
	}
;

UnaryExpr: PLUS UnaryExpr{
		auto temp = new SyntaxTree::UnaryExpr();
		temp->op = SyntaxTree::UnaryOp::PLUS;
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($2);
		$$ = temp;
		$$->loc = @$;
	}
	| MINUS UnaryExpr{
		auto temp = new SyntaxTree::UnaryExpr();
		temp->op = SyntaxTree::UnaryOp::MINUS;
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>($2);
		$$ = temp;
		$$->loc = @$;
	}
	| PrimaryExpr{
		$$ = $1;
	}
	| FuncCall{
		$$ = $1;
	}
;

PrimaryExpr: LPARENTHESE Exp RPARENTHESE{
		$$ = $2;
	}
	| LVal{
		$$ = $1;
	}
	| Number{
		$$ = $1;
	}
;

Number: INTCONST {
		$$ = new SyntaxTree::Literal();
		$$->literal_type = SyntaxTree::Type::INT;
		$$->int_const = $1;
		$$->loc = @$;
  	}
	| FLOATCONST {
		$$ = new SyntaxTree::Literal();
		$$->literal_type = SyntaxTree::Type::FLOAT;
		$$->float_const = $1;
		$$->loc = @$;
  	}
;

LVal: IDENTIFIER{
		$$ = new SyntaxTree::LVal();
		$$->name = $1;
		$$->loc = @$;
	}
	| IDENTIFIER LSQUARE Exp RSQUARE{
		$$ = new SyntaxTree::LVal();
		$$->name = $1;
		$$->array_index.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>($3));
		$$->loc = @$;
	}
;
%%

// Register errors to the driver:
void yy::sysyfParser::error (const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}

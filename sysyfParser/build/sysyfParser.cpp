// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "sysyfParser.h"


// Unqualified %code blocks.
#line 37 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"

#include "sysyfDriver.h"
#define yylex driver.lexer.yylex

#line 51 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 143 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"

  /// Build a parser object.
  sysyfParser::sysyfParser (sysyfDriver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  sysyfParser::~sysyfParser ()
  {}

  sysyfParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  sysyfParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  sysyfParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  sysyfParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  sysyfParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  sysyfParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  sysyfParser::symbol_kind_type
  sysyfParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  sysyfParser::stack_symbol_type::stack_symbol_type ()
  {}

  sysyfParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_CompUnit: // CompUnit
        value.YY_MOVE_OR_COPY< SyntaxTree::Assembly* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Block: // Block
        value.YY_MOVE_OR_COPY< SyntaxTree::BlockStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BreakStmt: // BreakStmt
        value.YY_MOVE_OR_COPY< SyntaxTree::BreakStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ContinueStmt: // ContinueStmt
        value.YY_MOVE_OR_COPY< SyntaxTree::ContinueStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Cond: // Cond
      case symbol_kind::S_EqExp: // EqExp
      case symbol_kind::S_RelExp: // RelExp
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_AddExp: // AddExp
      case symbol_kind::S_MulExp: // MulExp
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
        value.YY_MOVE_OR_COPY< SyntaxTree::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncCall: // FuncCall
        value.YY_MOVE_OR_COPY< SyntaxTree::FuncCallStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncDef: // FuncDef
        value.YY_MOVE_OR_COPY< SyntaxTree::FuncDef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncFParamList: // FuncFParamList
        value.YY_MOVE_OR_COPY< SyntaxTree::FuncFParamList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncParam: // FuncParam
        value.YY_MOVE_OR_COPY< SyntaxTree::FuncParam* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IfStmt: // IfStmt
        value.YY_MOVE_OR_COPY< SyntaxTree::IfStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_InitVal: // InitVal
        value.YY_MOVE_OR_COPY< SyntaxTree::InitVal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LVal: // LVal
        value.YY_MOVE_OR_COPY< SyntaxTree::LVal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.YY_MOVE_OR_COPY< SyntaxTree::Literal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExpList: // ExpList
        value.YY_MOVE_OR_COPY< SyntaxTree::PtrList<SyntaxTree::Expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GlobalDecl: // GlobalDecl
        value.YY_MOVE_OR_COPY< SyntaxTree::PtrList<SyntaxTree::GlobalDef> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BlockItemList: // BlockItemList
      case symbol_kind::S_BlockItem: // BlockItem
        value.YY_MOVE_OR_COPY< SyntaxTree::PtrList<SyntaxTree::Stmt> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_VarDefList: // VarDefList
        value.YY_MOVE_OR_COPY< SyntaxTree::PtrList<SyntaxTree::VarDef> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RetStmt: // RetStmt
        value.YY_MOVE_OR_COPY< SyntaxTree::ReturnStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.YY_MOVE_OR_COPY< SyntaxTree::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BType: // BType
        value.YY_MOVE_OR_COPY< SyntaxTree::Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDef: // VarDef
        value.YY_MOVE_OR_COPY< SyntaxTree::VarDef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WhileStmt: // WhileStmt
        value.YY_MOVE_OR_COPY< SyntaxTree::WhileStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATCONST: // FLOATCONST
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  sysyfParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_CompUnit: // CompUnit
        value.move< SyntaxTree::Assembly* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Block: // Block
        value.move< SyntaxTree::BlockStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BreakStmt: // BreakStmt
        value.move< SyntaxTree::BreakStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ContinueStmt: // ContinueStmt
        value.move< SyntaxTree::ContinueStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Cond: // Cond
      case symbol_kind::S_EqExp: // EqExp
      case symbol_kind::S_RelExp: // RelExp
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_AddExp: // AddExp
      case symbol_kind::S_MulExp: // MulExp
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
        value.move< SyntaxTree::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncCall: // FuncCall
        value.move< SyntaxTree::FuncCallStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncDef: // FuncDef
        value.move< SyntaxTree::FuncDef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncFParamList: // FuncFParamList
        value.move< SyntaxTree::FuncFParamList* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FuncParam: // FuncParam
        value.move< SyntaxTree::FuncParam* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IfStmt: // IfStmt
        value.move< SyntaxTree::IfStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_InitVal: // InitVal
        value.move< SyntaxTree::InitVal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LVal: // LVal
        value.move< SyntaxTree::LVal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Number: // Number
        value.move< SyntaxTree::Literal* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ExpList: // ExpList
        value.move< SyntaxTree::PtrList<SyntaxTree::Expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_GlobalDecl: // GlobalDecl
        value.move< SyntaxTree::PtrList<SyntaxTree::GlobalDef> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BlockItemList: // BlockItemList
      case symbol_kind::S_BlockItem: // BlockItem
        value.move< SyntaxTree::PtrList<SyntaxTree::Stmt> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_VarDefList: // VarDefList
        value.move< SyntaxTree::PtrList<SyntaxTree::VarDef> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_RetStmt: // RetStmt
        value.move< SyntaxTree::ReturnStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.move< SyntaxTree::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BType: // BType
        value.move< SyntaxTree::Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VarDef: // VarDef
        value.move< SyntaxTree::VarDef* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_WhileStmt: // WhileStmt
        value.move< SyntaxTree::WhileStmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOATCONST: // FLOATCONST
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  sysyfParser::stack_symbol_type&
  sysyfParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_CompUnit: // CompUnit
        value.copy< SyntaxTree::Assembly* > (that.value);
        break;

      case symbol_kind::S_Block: // Block
        value.copy< SyntaxTree::BlockStmt* > (that.value);
        break;

      case symbol_kind::S_BreakStmt: // BreakStmt
        value.copy< SyntaxTree::BreakStmt* > (that.value);
        break;

      case symbol_kind::S_ContinueStmt: // ContinueStmt
        value.copy< SyntaxTree::ContinueStmt* > (that.value);
        break;

      case symbol_kind::S_Cond: // Cond
      case symbol_kind::S_EqExp: // EqExp
      case symbol_kind::S_RelExp: // RelExp
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_AddExp: // AddExp
      case symbol_kind::S_MulExp: // MulExp
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
        value.copy< SyntaxTree::Expr* > (that.value);
        break;

      case symbol_kind::S_FuncCall: // FuncCall
        value.copy< SyntaxTree::FuncCallStmt* > (that.value);
        break;

      case symbol_kind::S_FuncDef: // FuncDef
        value.copy< SyntaxTree::FuncDef* > (that.value);
        break;

      case symbol_kind::S_FuncFParamList: // FuncFParamList
        value.copy< SyntaxTree::FuncFParamList* > (that.value);
        break;

      case symbol_kind::S_FuncParam: // FuncParam
        value.copy< SyntaxTree::FuncParam* > (that.value);
        break;

      case symbol_kind::S_IfStmt: // IfStmt
        value.copy< SyntaxTree::IfStmt* > (that.value);
        break;

      case symbol_kind::S_InitVal: // InitVal
        value.copy< SyntaxTree::InitVal* > (that.value);
        break;

      case symbol_kind::S_LVal: // LVal
        value.copy< SyntaxTree::LVal* > (that.value);
        break;

      case symbol_kind::S_Number: // Number
        value.copy< SyntaxTree::Literal* > (that.value);
        break;

      case symbol_kind::S_ExpList: // ExpList
        value.copy< SyntaxTree::PtrList<SyntaxTree::Expr> > (that.value);
        break;

      case symbol_kind::S_GlobalDecl: // GlobalDecl
        value.copy< SyntaxTree::PtrList<SyntaxTree::GlobalDef> > (that.value);
        break;

      case symbol_kind::S_BlockItemList: // BlockItemList
      case symbol_kind::S_BlockItem: // BlockItem
        value.copy< SyntaxTree::PtrList<SyntaxTree::Stmt> > (that.value);
        break;

      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_VarDefList: // VarDefList
        value.copy< SyntaxTree::PtrList<SyntaxTree::VarDef> > (that.value);
        break;

      case symbol_kind::S_RetStmt: // RetStmt
        value.copy< SyntaxTree::ReturnStmt* > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.copy< SyntaxTree::Stmt* > (that.value);
        break;

      case symbol_kind::S_BType: // BType
        value.copy< SyntaxTree::Type > (that.value);
        break;

      case symbol_kind::S_VarDef: // VarDef
        value.copy< SyntaxTree::VarDef* > (that.value);
        break;

      case symbol_kind::S_WhileStmt: // WhileStmt
        value.copy< SyntaxTree::WhileStmt* > (that.value);
        break;

      case symbol_kind::S_FLOATCONST: // FLOATCONST
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  sysyfParser::stack_symbol_type&
  sysyfParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_CompUnit: // CompUnit
        value.move< SyntaxTree::Assembly* > (that.value);
        break;

      case symbol_kind::S_Block: // Block
        value.move< SyntaxTree::BlockStmt* > (that.value);
        break;

      case symbol_kind::S_BreakStmt: // BreakStmt
        value.move< SyntaxTree::BreakStmt* > (that.value);
        break;

      case symbol_kind::S_ContinueStmt: // ContinueStmt
        value.move< SyntaxTree::ContinueStmt* > (that.value);
        break;

      case symbol_kind::S_Cond: // Cond
      case symbol_kind::S_EqExp: // EqExp
      case symbol_kind::S_RelExp: // RelExp
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_AddExp: // AddExp
      case symbol_kind::S_MulExp: // MulExp
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
        value.move< SyntaxTree::Expr* > (that.value);
        break;

      case symbol_kind::S_FuncCall: // FuncCall
        value.move< SyntaxTree::FuncCallStmt* > (that.value);
        break;

      case symbol_kind::S_FuncDef: // FuncDef
        value.move< SyntaxTree::FuncDef* > (that.value);
        break;

      case symbol_kind::S_FuncFParamList: // FuncFParamList
        value.move< SyntaxTree::FuncFParamList* > (that.value);
        break;

      case symbol_kind::S_FuncParam: // FuncParam
        value.move< SyntaxTree::FuncParam* > (that.value);
        break;

      case symbol_kind::S_IfStmt: // IfStmt
        value.move< SyntaxTree::IfStmt* > (that.value);
        break;

      case symbol_kind::S_InitVal: // InitVal
        value.move< SyntaxTree::InitVal* > (that.value);
        break;

      case symbol_kind::S_LVal: // LVal
        value.move< SyntaxTree::LVal* > (that.value);
        break;

      case symbol_kind::S_Number: // Number
        value.move< SyntaxTree::Literal* > (that.value);
        break;

      case symbol_kind::S_ExpList: // ExpList
        value.move< SyntaxTree::PtrList<SyntaxTree::Expr> > (that.value);
        break;

      case symbol_kind::S_GlobalDecl: // GlobalDecl
        value.move< SyntaxTree::PtrList<SyntaxTree::GlobalDef> > (that.value);
        break;

      case symbol_kind::S_BlockItemList: // BlockItemList
      case symbol_kind::S_BlockItem: // BlockItem
        value.move< SyntaxTree::PtrList<SyntaxTree::Stmt> > (that.value);
        break;

      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_VarDefList: // VarDefList
        value.move< SyntaxTree::PtrList<SyntaxTree::VarDef> > (that.value);
        break;

      case symbol_kind::S_RetStmt: // RetStmt
        value.move< SyntaxTree::ReturnStmt* > (that.value);
        break;

      case symbol_kind::S_Stmt: // Stmt
        value.move< SyntaxTree::Stmt* > (that.value);
        break;

      case symbol_kind::S_BType: // BType
        value.move< SyntaxTree::Type > (that.value);
        break;

      case symbol_kind::S_VarDef: // VarDef
        value.move< SyntaxTree::VarDef* > (that.value);
        break;

      case symbol_kind::S_WhileStmt: // WhileStmt
        value.move< SyntaxTree::WhileStmt* > (that.value);
        break;

      case symbol_kind::S_FLOATCONST: // FLOATCONST
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  sysyfParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  sysyfParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  sysyfParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  sysyfParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  sysyfParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  sysyfParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  sysyfParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  sysyfParser::debug_level_type
  sysyfParser::debug_level () const
  {
    return yydebug_;
  }

  void
  sysyfParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  sysyfParser::state_type
  sysyfParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  sysyfParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  sysyfParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  sysyfParser::operator() ()
  {
    return parse ();
  }

  int
  sysyfParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 26 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
{
// Initialize the initial location.
yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 845 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_CompUnit: // CompUnit
        yylhs.value.emplace< SyntaxTree::Assembly* > ();
        break;

      case symbol_kind::S_Block: // Block
        yylhs.value.emplace< SyntaxTree::BlockStmt* > ();
        break;

      case symbol_kind::S_BreakStmt: // BreakStmt
        yylhs.value.emplace< SyntaxTree::BreakStmt* > ();
        break;

      case symbol_kind::S_ContinueStmt: // ContinueStmt
        yylhs.value.emplace< SyntaxTree::ContinueStmt* > ();
        break;

      case symbol_kind::S_Cond: // Cond
      case symbol_kind::S_EqExp: // EqExp
      case symbol_kind::S_RelExp: // RelExp
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_AddExp: // AddExp
      case symbol_kind::S_MulExp: // MulExp
      case symbol_kind::S_UnaryExpr: // UnaryExpr
      case symbol_kind::S_PrimaryExpr: // PrimaryExpr
        yylhs.value.emplace< SyntaxTree::Expr* > ();
        break;

      case symbol_kind::S_FuncCall: // FuncCall
        yylhs.value.emplace< SyntaxTree::FuncCallStmt* > ();
        break;

      case symbol_kind::S_FuncDef: // FuncDef
        yylhs.value.emplace< SyntaxTree::FuncDef* > ();
        break;

      case symbol_kind::S_FuncFParamList: // FuncFParamList
        yylhs.value.emplace< SyntaxTree::FuncFParamList* > ();
        break;

      case symbol_kind::S_FuncParam: // FuncParam
        yylhs.value.emplace< SyntaxTree::FuncParam* > ();
        break;

      case symbol_kind::S_IfStmt: // IfStmt
        yylhs.value.emplace< SyntaxTree::IfStmt* > ();
        break;

      case symbol_kind::S_InitVal: // InitVal
        yylhs.value.emplace< SyntaxTree::InitVal* > ();
        break;

      case symbol_kind::S_LVal: // LVal
        yylhs.value.emplace< SyntaxTree::LVal* > ();
        break;

      case symbol_kind::S_Number: // Number
        yylhs.value.emplace< SyntaxTree::Literal* > ();
        break;

      case symbol_kind::S_ExpList: // ExpList
        yylhs.value.emplace< SyntaxTree::PtrList<SyntaxTree::Expr> > ();
        break;

      case symbol_kind::S_GlobalDecl: // GlobalDecl
        yylhs.value.emplace< SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ();
        break;

      case symbol_kind::S_BlockItemList: // BlockItemList
      case symbol_kind::S_BlockItem: // BlockItem
        yylhs.value.emplace< SyntaxTree::PtrList<SyntaxTree::Stmt> > ();
        break;

      case symbol_kind::S_VarDecl: // VarDecl
      case symbol_kind::S_VarDefList: // VarDefList
        yylhs.value.emplace< SyntaxTree::PtrList<SyntaxTree::VarDef> > ();
        break;

      case symbol_kind::S_RetStmt: // RetStmt
        yylhs.value.emplace< SyntaxTree::ReturnStmt* > ();
        break;

      case symbol_kind::S_Stmt: // Stmt
        yylhs.value.emplace< SyntaxTree::Stmt* > ();
        break;

      case symbol_kind::S_BType: // BType
        yylhs.value.emplace< SyntaxTree::Type > ();
        break;

      case symbol_kind::S_VarDef: // VarDef
        yylhs.value.emplace< SyntaxTree::VarDef* > ();
        break;

      case symbol_kind::S_WhileStmt: // WhileStmt
        yylhs.value.emplace< SyntaxTree::WhileStmt* > ();
        break;

      case symbol_kind::S_FLOATCONST: // FLOATCONST
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Begin: CompUnit END
#line 104 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                    {
	yystack_[1].value.as < SyntaxTree::Assembly* > ()->loc = yylhs.location;
	driver.root = yystack_[1].value.as < SyntaxTree::Assembly* > ();
	return 0;
}
#line 1096 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 3: // CompUnit: CompUnit GlobalDecl
#line 111 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                            {
		yystack_[1].value.as < SyntaxTree::Assembly* > ()->global_defs.insert(yystack_[1].value.as < SyntaxTree::Assembly* > ()->global_defs.end(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().begin(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().end());
		yylhs.value.as < SyntaxTree::Assembly* > ()=yystack_[1].value.as < SyntaxTree::Assembly* > ();
	}
#line 1105 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 4: // CompUnit: GlobalDecl
#line 115 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                    {
		yylhs.value.as < SyntaxTree::Assembly* > ()=new SyntaxTree::Assembly();
		yylhs.value.as < SyntaxTree::Assembly* > ()->global_defs.insert(yylhs.value.as < SyntaxTree::Assembly* > ()->global_defs.end(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().begin(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().end());
  	}
#line 1114 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 5: // GlobalDecl: FuncDef
#line 121 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                  {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ()=SyntaxTree::PtrList<SyntaxTree::GlobalDef>();
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().push_back(SyntaxTree::Ptr<SyntaxTree::GlobalDef>(yystack_[0].value.as < SyntaxTree::FuncDef* > ()));
  	}
#line 1123 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 6: // GlobalDecl: VarDecl
#line 125 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ()=SyntaxTree::PtrList<SyntaxTree::GlobalDef>();
		for (auto i : yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ())
		{
			yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::GlobalDef> > ().push_back(SyntaxTree::Ptr<SyntaxTree::GlobalDef>(i));
		}
  	}
#line 1135 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 7: // BType: VOID
#line 134 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
           {
		yylhs.value.as < SyntaxTree::Type > ()=SyntaxTree::Type::VOID;
	}
#line 1143 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 8: // BType: INT
#line 137 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
             {
		yylhs.value.as < SyntaxTree::Type > ()=SyntaxTree::Type::INT;
  	}
#line 1151 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 9: // BType: FLOAT
#line 140 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
               {
		yylhs.value.as < SyntaxTree::Type > ()=SyntaxTree::Type::FLOAT;
  	}
#line 1159 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 10: // VarDecl: CONST BType VarDefList SEMICOLON
#line 145 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                         {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()=yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ();
		for (auto &node : yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()) {
			node->is_constant = true;
			node->btype = yystack_[2].value.as < SyntaxTree::Type > ();
		}
	}
#line 1171 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 11: // VarDecl: BType VarDefList SEMICOLON
#line 152 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                    {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()=yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ();
		for (auto &node : yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()) {
			node->btype = yystack_[2].value.as < SyntaxTree::Type > ();
		}
	}
#line 1182 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 12: // VarDefList: VarDefList COMMA VarDef
#line 160 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                  {
		yystack_[2].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ().push_back(SyntaxTree::Ptr<SyntaxTree::VarDef>(yystack_[0].value.as < SyntaxTree::VarDef* > ()));
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()=yystack_[2].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ();
	}
#line 1191 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 13: // VarDefList: VarDef
#line 164 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ()=SyntaxTree::PtrList<SyntaxTree::VarDef>();
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ().push_back(SyntaxTree::Ptr<SyntaxTree::VarDef>(yystack_[0].value.as < SyntaxTree::VarDef* > ()));
	}
#line 1200 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 14: // VarDef: IDENTIFIER
#line 170 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::VarDef* > ()=new SyntaxTree::VarDef();
		yylhs.value.as < SyntaxTree::VarDef* > ()->name=yystack_[0].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::VarDef* > ()->is_inited = false;
		yylhs.value.as < SyntaxTree::VarDef* > ()->loc = yylhs.location;
	}
#line 1211 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 15: // VarDef: IDENTIFIER LSQUARE Exp RSQUARE
#line 176 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                        {
		yylhs.value.as < SyntaxTree::VarDef* > ()=new SyntaxTree::VarDef();
		yylhs.value.as < SyntaxTree::VarDef* > ()->name=yystack_[3].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::VarDef* > ()->is_inited = false;
		yylhs.value.as < SyntaxTree::VarDef* > ()->array_length.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[1].value.as < SyntaxTree::Expr* > ()));
		yylhs.value.as < SyntaxTree::VarDef* > ()->loc = yylhs.location;
	}
#line 1223 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 16: // VarDef: IDENTIFIER ASSIGN InitVal
#line 183 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                   {
		yylhs.value.as < SyntaxTree::VarDef* > () = new SyntaxTree::VarDef();
		yylhs.value.as < SyntaxTree::VarDef* > ()->name = yystack_[2].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::VarDef* > ()->initializers = SyntaxTree::Ptr<SyntaxTree::InitVal>(yystack_[0].value.as < SyntaxTree::InitVal* > ());
		yylhs.value.as < SyntaxTree::VarDef* > ()->is_inited = true;
		yylhs.value.as < SyntaxTree::VarDef* > ()->loc = yylhs.location;
	}
#line 1235 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 17: // VarDef: IDENTIFIER LSQUARE Exp RSQUARE ASSIGN InitVal
#line 190 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                                       {
		yylhs.value.as < SyntaxTree::VarDef* > () = new SyntaxTree::VarDef();
		yylhs.value.as < SyntaxTree::VarDef* > ()->name = yystack_[5].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::VarDef* > ()->initializers = SyntaxTree::Ptr<SyntaxTree::InitVal>(yystack_[0].value.as < SyntaxTree::InitVal* > ());
		yylhs.value.as < SyntaxTree::VarDef* > ()->array_length.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[3].value.as < SyntaxTree::Expr* > ()));
		yylhs.value.as < SyntaxTree::VarDef* > ()->is_inited = true;
		yylhs.value.as < SyntaxTree::VarDef* > ()->loc = yylhs.location;
	}
#line 1248 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 18: // InitVal: LBRACE RBRACE
#line 200 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                      {
		yylhs.value.as < SyntaxTree::InitVal* > () = new SyntaxTree::InitVal();
		yylhs.value.as < SyntaxTree::InitVal* > ()->isExp = false;
	}
#line 1257 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 19: // InitVal: LBRACE ExpList RBRACE
#line 204 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                               {
		yylhs.value.as < SyntaxTree::InitVal* > () = new SyntaxTree::InitVal();
		yylhs.value.as < SyntaxTree::InitVal* > ()->isExp = false;
		for (auto i : yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > ())
		{
			auto tmp = new SyntaxTree::InitVal();
			tmp->isExp = true;
			tmp->expr = SyntaxTree::Ptr<SyntaxTree::Expr>(i);
			yylhs.value.as < SyntaxTree::InitVal* > ()->elementList.push_back(SyntaxTree::Ptr<SyntaxTree::InitVal>(tmp));
		}
	}
#line 1273 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 20: // InitVal: Exp
#line 215 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
             {
		yylhs.value.as < SyntaxTree::InitVal* > () = new SyntaxTree::InitVal();
		yylhs.value.as < SyntaxTree::InitVal* > ()->isExp = true;
		yylhs.value.as < SyntaxTree::InitVal* > ()->expr = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::InitVal* > ()->loc = yylhs.location;
	}
#line 1284 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 21: // FuncCall: IDENTIFIER LPARENTHESE ExpList RPARENTHESE
#line 223 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                                     {
		yylhs.value.as < SyntaxTree::FuncCallStmt* > () = new SyntaxTree::FuncCallStmt();
		yylhs.value.as < SyntaxTree::FuncCallStmt* > ()->name = yystack_[3].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::FuncCallStmt* > ()->params = yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > ();
		yylhs.value.as < SyntaxTree::FuncCallStmt* > ()->loc = yylhs.location;
	}
#line 1295 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 22: // FuncCall: IDENTIFIER LPARENTHESE RPARENTHESE
#line 229 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                             {
		yylhs.value.as < SyntaxTree::FuncCallStmt* > () = new SyntaxTree::FuncCallStmt();
		yylhs.value.as < SyntaxTree::FuncCallStmt* > ()->name = yystack_[2].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::FuncCallStmt* > ()->loc = yylhs.location;
	}
#line 1305 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 23: // FuncDef: BType IDENTIFIER LPARENTHESE FuncFParamList RPARENTHESE Block
#line 236 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                                                      {
		yylhs.value.as < SyntaxTree::FuncDef* > () = new SyntaxTree::FuncDef();
		yylhs.value.as < SyntaxTree::FuncDef* > ()->ret_type = yystack_[5].value.as < SyntaxTree::Type > ();
		yylhs.value.as < SyntaxTree::FuncDef* > ()->param_list = SyntaxTree::Ptr<SyntaxTree::FuncFParamList>(yystack_[2].value.as < SyntaxTree::FuncFParamList* > ());
		yylhs.value.as < SyntaxTree::FuncDef* > ()->name = yystack_[4].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::FuncDef* > ()->body = SyntaxTree::Ptr<SyntaxTree::BlockStmt>(yystack_[0].value.as < SyntaxTree::BlockStmt* > ());
		yylhs.value.as < SyntaxTree::FuncDef* > ()->loc = yylhs.location;
	}
#line 1318 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 24: // FuncFParamList: FuncFParamList COMMA FuncParam
#line 246 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                              {
		yystack_[2].value.as < SyntaxTree::FuncFParamList* > ()->params.push_back(SyntaxTree::Ptr<SyntaxTree::FuncParam>(yystack_[0].value.as < SyntaxTree::FuncParam* > ()));
		yylhs.value.as < SyntaxTree::FuncFParamList* > ()=yystack_[2].value.as < SyntaxTree::FuncFParamList* > ();
	}
#line 1327 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 25: // FuncFParamList: FuncParam
#line 250 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                   {
		yylhs.value.as < SyntaxTree::FuncFParamList* > () = new SyntaxTree::FuncFParamList();
		yylhs.value.as < SyntaxTree::FuncFParamList* > ()->params.push_back(SyntaxTree::Ptr<SyntaxTree::FuncParam>(yystack_[0].value.as < SyntaxTree::FuncParam* > ()));
	}
#line 1336 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 26: // FuncFParamList: %empty
#line 254 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::FuncFParamList* > () = new SyntaxTree::FuncFParamList();
	}
#line 1344 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 27: // FuncParam: BType IDENTIFIER
#line 259 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                           {
		yylhs.value.as < SyntaxTree::FuncParam* > () = new SyntaxTree::FuncParam();
		yylhs.value.as < SyntaxTree::FuncParam* > ()->name = yystack_[0].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::FuncParam* > ()->param_type = yystack_[1].value.as < SyntaxTree::Type > ();
		yylhs.value.as < SyntaxTree::FuncParam* > ()->loc = yylhs.location;
	}
#line 1355 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 28: // Block: LBRACE BlockItemList RBRACE
#line 267 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                 {
		yylhs.value.as < SyntaxTree::BlockStmt* > () = new SyntaxTree::BlockStmt();
		yylhs.value.as < SyntaxTree::BlockStmt* > ()->body = yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ();
		yylhs.value.as < SyntaxTree::BlockStmt* > ()->loc = yylhs.location;
	}
#line 1365 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 29: // BlockItemList: BlockItemList BlockItem
#line 274 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                     {
		yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().insert(yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().end(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().begin(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().end());
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > () = yystack_[1].value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ();
	}
#line 1374 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 30: // BlockItemList: %empty
#line 278 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > () = SyntaxTree::PtrList<SyntaxTree::Stmt>();
	}
#line 1382 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 31: // BlockItem: VarDecl
#line 283 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > () = SyntaxTree::PtrList<SyntaxTree::Stmt>();
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().insert(yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().end(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ().begin(), yystack_[0].value.as < SyntaxTree::PtrList<SyntaxTree::VarDef> > ().end());
	}
#line 1391 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 32: // BlockItem: Stmt
#line 287 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
              {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > () = SyntaxTree::PtrList<SyntaxTree::Stmt>();
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Stmt> > ().push_back(SyntaxTree::Ptr<SyntaxTree::Stmt>(yystack_[0].value.as < SyntaxTree::Stmt* > ()));
	}
#line 1400 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 33: // Stmt: LVal ASSIGN Exp SEMICOLON
#line 293 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                              {
		auto temp = new SyntaxTree::AssignStmt();
		temp->target = SyntaxTree::Ptr<SyntaxTree::LVal>(yystack_[3].value.as < SyntaxTree::LVal* > ());
		temp->value = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[1].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Stmt* > () = temp;
		yylhs.value.as < SyntaxTree::Stmt* > ()->loc = yylhs.location;
	}
#line 1412 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 34: // Stmt: Exp SEMICOLON
#line 300 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                       {
		auto temp = new SyntaxTree::ExprStmt();
		temp->exp = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[1].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Stmt* > () = temp;
		yylhs.value.as < SyntaxTree::Stmt* > ()->loc = yylhs.location;
	}
#line 1423 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 35: // Stmt: Block
#line 306 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
               {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::BlockStmt* > ();
	}
#line 1431 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 36: // Stmt: SEMICOLON
#line 309 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                   {
		yylhs.value.as < SyntaxTree::Stmt* > () = new SyntaxTree::EmptyStmt();
		yylhs.value.as < SyntaxTree::Stmt* > ()->loc = yylhs.location;
	}
#line 1440 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 37: // Stmt: IfStmt
#line 313 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::IfStmt* > ();
	}
#line 1448 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 38: // Stmt: WhileStmt
#line 316 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                   {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::WhileStmt* > ();
	}
#line 1456 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 39: // Stmt: BreakStmt
#line 319 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                   {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::BreakStmt* > ();
	}
#line 1464 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 40: // Stmt: ContinueStmt
#line 322 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                      {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::ContinueStmt* > ();
	}
#line 1472 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 41: // Stmt: RetStmt
#line 325 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::Stmt* > () = yystack_[0].value.as < SyntaxTree::ReturnStmt* > ();
	}
#line 1480 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 42: // RetStmt: RETURN Exp SEMICOLON
#line 330 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                             {
		yylhs.value.as < SyntaxTree::ReturnStmt* > () = new SyntaxTree::ReturnStmt();
		yylhs.value.as < SyntaxTree::ReturnStmt* > ()->ret = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[1].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::ReturnStmt* > ()->loc = yylhs.location;
	}
#line 1490 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 43: // RetStmt: RETURN SEMICOLON
#line 335 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                          {
		auto temp = new SyntaxTree::ReturnStmt();
		yylhs.value.as < SyntaxTree::ReturnStmt* > () = temp;
		yylhs.value.as < SyntaxTree::ReturnStmt* > ()->loc = yylhs.location;
	}
#line 1500 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 44: // IfStmt: IF LPARENTHESE Cond RPARENTHESE Stmt ELSE Stmt
#line 342 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                                      {
		yylhs.value.as < SyntaxTree::IfStmt* > () = new SyntaxTree::IfStmt();
		yylhs.value.as < SyntaxTree::IfStmt* > ()->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[4].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::IfStmt* > ()->if_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>(yystack_[2].value.as < SyntaxTree::Stmt* > ());
		yylhs.value.as < SyntaxTree::IfStmt* > ()->else_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>(yystack_[0].value.as < SyntaxTree::Stmt* > ());
	}
#line 1511 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 45: // IfStmt: IF LPARENTHESE Cond RPARENTHESE Stmt
#line 348 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                              {
		yylhs.value.as < SyntaxTree::IfStmt* > () = new SyntaxTree::IfStmt();
		yylhs.value.as < SyntaxTree::IfStmt* > ()->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::IfStmt* > ()->if_statement = SyntaxTree::Ptr<SyntaxTree::Stmt>(yystack_[0].value.as < SyntaxTree::Stmt* > ());
	}
#line 1521 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 46: // WhileStmt: WHILE LPARENTHESE Cond RPARENTHESE Stmt
#line 355 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                                  {
		yylhs.value.as < SyntaxTree::WhileStmt* > () = new SyntaxTree::WhileStmt();
		yylhs.value.as < SyntaxTree::WhileStmt* > ()->cond_exp = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::WhileStmt* > ()->statement = SyntaxTree::Ptr<SyntaxTree::Stmt>(yystack_[0].value.as < SyntaxTree::Stmt* > ());
	}
#line 1531 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 47: // BreakStmt: BREAK SEMICOLON
#line 362 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                          {
		yylhs.value.as < SyntaxTree::BreakStmt* > () = new SyntaxTree::BreakStmt();
	}
#line 1539 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 48: // ContinueStmt: CONTINUE SEMICOLON
#line 367 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                {
		yylhs.value.as < SyntaxTree::ContinueStmt* > () = new SyntaxTree::ContinueStmt();
	}
#line 1547 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 49: // ExpList: ExpList COMMA Exp
#line 372 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                          {
		yystack_[2].value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > ().push_back(SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ()));
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > () = yystack_[2].value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > ();
	}
#line 1556 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 50: // ExpList: Exp
#line 376 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
             {
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > () = SyntaxTree::PtrList<SyntaxTree::Expr>();
		yylhs.value.as < SyntaxTree::PtrList<SyntaxTree::Expr> > ().push_back(SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ()));
	}
#line 1565 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 51: // Cond: EqExp
#line 382 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
           {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1573 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 52: // EqExp: RelExp
#line 387 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
             {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1581 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 53: // EqExp: EqExp EQ RelExp
#line 390 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                         {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::EQ;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1594 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 54: // EqExp: EqExp NEQ RelExp
#line 398 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                          {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::NEQ;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1607 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 55: // RelExp: AddExp
#line 408 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
              {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1615 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 56: // RelExp: RelExp LT AddExp
#line 411 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                           {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::LT;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1628 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 57: // RelExp: RelExp GT AddExp
#line 419 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                           {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::GT;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1641 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 58: // RelExp: RelExp LE AddExp
#line 427 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                           {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::LTE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1654 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 59: // RelExp: RelExp GE AddExp
#line 435 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                           {
		auto temp = new SyntaxTree::BinaryCondExpr();
		temp->op = SyntaxTree::BinaryCondOp::GTE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1667 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 60: // Exp: AddExp
#line 445 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
           {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1675 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 61: // AddExp: MulExp
#line 450 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
              {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1683 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 62: // AddExp: AddExp PLUS MulExp
#line 453 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                            {
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::PLUS;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1696 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 63: // AddExp: AddExp MINUS MulExp
#line 461 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                             {
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MINUS;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1709 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 64: // MulExp: UnaryExpr
#line 471 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1717 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 65: // MulExp: MulExp MULTIPLY UnaryExpr
#line 474 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                   {
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MULTIPLY;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1730 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 66: // MulExp: MulExp DIVIDE UnaryExpr
#line 482 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                 {
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::DIVIDE;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1743 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 67: // MulExp: MulExp MODULO UnaryExpr
#line 490 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                 {
		auto temp = new SyntaxTree::BinaryExpr();
		temp->op = SyntaxTree::BinOp::MODULO;
		temp->lhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[2].value.as < SyntaxTree::Expr* > ());
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1756 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 68: // UnaryExpr: PLUS UnaryExpr
#line 500 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                         {
		auto temp = new SyntaxTree::UnaryExpr();
		temp->op = SyntaxTree::UnaryOp::PLUS;
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1768 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 69: // UnaryExpr: MINUS UnaryExpr
#line 507 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                         {
		auto temp = new SyntaxTree::UnaryExpr();
		temp->op = SyntaxTree::UnaryOp::MINUS;
		temp->rhs = SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[0].value.as < SyntaxTree::Expr* > ());
		yylhs.value.as < SyntaxTree::Expr* > () = temp;
		yylhs.value.as < SyntaxTree::Expr* > ()->loc = yylhs.location;
	}
#line 1780 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 70: // UnaryExpr: PrimaryExpr
#line 514 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                     {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Expr* > ();
	}
#line 1788 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 71: // UnaryExpr: FuncCall
#line 517 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                  {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::FuncCallStmt* > ();
	}
#line 1796 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 72: // PrimaryExpr: LPARENTHESE Exp RPARENTHESE
#line 522 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                        {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[1].value.as < SyntaxTree::Expr* > ();
	}
#line 1804 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 73: // PrimaryExpr: LVal
#line 525 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
              {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::LVal* > ();
	}
#line 1812 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 74: // PrimaryExpr: Number
#line 528 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::Expr* > () = yystack_[0].value.as < SyntaxTree::Literal* > ();
	}
#line 1820 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 75: // Number: INTCONST
#line 533 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                 {
		yylhs.value.as < SyntaxTree::Literal* > () = new SyntaxTree::Literal();
		yylhs.value.as < SyntaxTree::Literal* > ()->literal_type = SyntaxTree::Type::INT;
		yylhs.value.as < SyntaxTree::Literal* > ()->int_const = yystack_[0].value.as < int > ();
		yylhs.value.as < SyntaxTree::Literal* > ()->loc = yylhs.location;
  	}
#line 1831 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 76: // Number: FLOATCONST
#line 539 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                     {
		yylhs.value.as < SyntaxTree::Literal* > () = new SyntaxTree::Literal();
		yylhs.value.as < SyntaxTree::Literal* > ()->literal_type = SyntaxTree::Type::FLOAT;
		yylhs.value.as < SyntaxTree::Literal* > ()->float_const = yystack_[0].value.as < double > ();
		yylhs.value.as < SyntaxTree::Literal* > ()->loc = yylhs.location;
  	}
#line 1842 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 77: // LVal: IDENTIFIER
#line 547 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                {
		yylhs.value.as < SyntaxTree::LVal* > () = new SyntaxTree::LVal();
		yylhs.value.as < SyntaxTree::LVal* > ()->name = yystack_[0].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::LVal* > ()->loc = yylhs.location;
	}
#line 1852 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;

  case 78: // LVal: IDENTIFIER LSQUARE Exp RSQUARE
#line 552 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"
                                        {
		yylhs.value.as < SyntaxTree::LVal* > () = new SyntaxTree::LVal();
		yylhs.value.as < SyntaxTree::LVal* > ()->name = yystack_[3].value.as < std::string > ();
		yylhs.value.as < SyntaxTree::LVal* > ()->array_index.push_back(SyntaxTree::Ptr<SyntaxTree::Expr>(yystack_[1].value.as < SyntaxTree::Expr* > ()));
		yylhs.value.as < SyntaxTree::LVal* > ()->loc = yylhs.location;
	}
#line 1863 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"
    break;


#line 1867 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  sysyfParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  sysyfParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  sysyfParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // sysyfParser::context.
  sysyfParser::context::context (const sysyfParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  sysyfParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  sysyfParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  sysyfParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char sysyfParser::yypact_ninf_ = -106;

  const signed char sysyfParser::yytable_ninf_ = -1;

  const short
  sysyfParser::yypact_[] =
  {
      29,    38,  -106,  -106,  -106,     7,   123,  -106,   -19,  -106,
    -106,    -8,  -106,  -106,  -106,     5,    66,  -106,    34,   107,
      95,    38,   101,  -106,    -8,  -106,   101,   101,   101,    98,
      61,  -106,  -106,  -106,  -106,  -106,   115,    57,  -106,  -106,
    -106,  -106,    10,    75,  -106,    42,  -106,  -106,  -106,    78,
    -106,    -5,  -106,    19,   101,   101,   101,   101,   101,   101,
    -106,    38,    85,   103,  -106,   101,  -106,  -106,    76,    89,
      57,    57,  -106,  -106,  -106,  -106,  -106,  -106,    95,  -106,
    -106,  -106,    62,  -106,  -106,  -106,   113,   130,   141,   142,
     104,    -8,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,   145,   148,   101,   101,  -106,  -106,  -106,   149,  -106,
     101,   147,    97,    23,   115,   150,  -106,   151,     6,   101,
     101,   101,   101,   101,   101,     6,  -106,   138,    23,    23,
     115,   115,   115,   115,  -106,     6,  -106
  };

  const signed char
  sysyfParser::yydefact_[] =
  {
       0,     0,     8,     9,     7,     0,     0,     4,     0,     6,
       5,     0,     1,     2,     3,    14,     0,    13,    14,     0,
       0,    26,     0,    11,     0,    10,     0,     0,     0,     0,
      77,    75,    76,    16,    71,    20,    60,    61,    64,    70,
      74,    73,     0,     0,    25,     0,    12,    68,    69,     0,
      18,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    15,    72,     0,    19,    22,     0,     0,
      62,    63,    65,    66,    67,    24,    30,    23,     0,    49,
      21,    78,     0,    17,    36,    28,     0,     0,     0,     0,
       0,     0,    31,    35,    29,    32,    41,    37,    38,    39,
      40,     0,    73,     0,     0,    47,    48,    43,     0,    34,
       0,     0,    51,    52,    55,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    45,    53,    54,
      56,    57,    58,    59,    46,     0,    44
  };

  const short
  sysyfParser::yypgoto_[] =
  {
    -106,  -106,  -106,   156,     0,    82,   154,   143,    88,  -106,
    -106,  -106,   108,   106,  -106,  -106,  -105,  -106,  -106,  -106,
    -106,  -106,   117,    67,  -106,     4,   -20,    24,    94,   -22,
    -106,  -106,   -79
  };

  const signed char
  sysyfParser::yydefgoto_[] =
  {
       0,     5,     6,     7,     8,     9,    16,    17,    33,    34,
      10,    43,    44,    93,    82,    94,    95,    96,    97,    98,
      99,   100,    51,   111,   112,   113,   101,    36,    37,    38,
      39,    40,    41
  };

  const unsigned char
  sysyfParser::yytable_[] =
  {
      35,    11,    45,   102,    47,    48,    65,    12,    49,    52,
      26,    27,    66,   127,    20,    15,    84,    21,    28,    22,
     134,    42,    76,    26,    27,    86,    18,    87,    88,    89,
     136,    28,    67,    52,    69,    72,    73,    74,    90,   102,
      30,    31,    32,    20,    60,    79,   102,     1,    22,   121,
     122,   123,   124,    30,    31,    32,   102,    63,    35,     2,
       3,    42,     4,    57,    58,    59,    26,    27,     2,     3,
     108,     4,    84,    53,    28,    54,    23,    24,    76,    85,
       1,    86,    91,    87,    88,    89,    61,    65,    62,    80,
     117,    64,     2,     3,    90,     4,    30,    31,    32,    26,
      27,    76,    26,    27,    81,    26,    27,    28,    26,    27,
      28,    29,    78,    28,   107,    50,    28,    25,    24,    55,
      56,   119,   120,   128,   129,   103,    13,   114,   114,    30,
      31,    32,    30,    31,    32,    30,    31,    32,    30,    31,
      32,     1,   104,   114,   114,   130,   131,   132,   133,    70,
      71,   105,   106,     2,     3,   109,     4,   110,   135,   116,
     118,   126,    14,   125,    92,    19,    83,    46,    77,    75,
      68,   115
  };

  const unsigned char
  sysyfParser::yycheck_[] =
  {
      20,     1,    22,    82,    26,    27,    11,     0,    28,    29,
       4,     5,    17,   118,     9,    34,    10,    12,    12,    14,
     125,    21,    16,     4,     5,    19,    34,    21,    22,    23,
     135,    12,    13,    53,    54,    57,    58,    59,    32,   118,
      34,    35,    36,     9,    34,    65,   125,    18,    14,    26,
      27,    28,    29,    34,    35,    36,   135,    15,    78,    30,
      31,    61,    33,     6,     7,     8,     4,     5,    30,    31,
      90,    33,    10,    12,    12,    14,    10,    11,    16,    17,
      18,    19,    82,    21,    22,    23,    11,    11,    13,    13,
     110,    13,    30,    31,    32,    33,    34,    35,    36,     4,
       5,    16,     4,     5,    15,     4,     5,    12,     4,     5,
      12,    16,     9,    12,    10,    17,    12,    10,    11,     4,
       5,    24,    25,   119,   120,    12,     3,   103,   104,    34,
      35,    36,    34,    35,    36,    34,    35,    36,    34,    35,
      36,    18,    12,   119,   120,   121,   122,   123,   124,    55,
      56,    10,    10,    30,    31,    10,    33,     9,    20,    10,
      13,    10,     6,    13,    82,    11,    78,    24,    62,    61,
      53,   104
  };

  const signed char
  sysyfParser::yystos_[] =
  {
       0,    18,    30,    31,    33,    42,    43,    44,    45,    46,
      51,    45,     0,     3,    44,    34,    47,    48,    34,    47,
       9,    12,    14,    10,    11,    10,     4,     5,    12,    16,
      34,    35,    36,    49,    50,    67,    68,    69,    70,    71,
      72,    73,    45,    52,    53,    67,    48,    70,    70,    67,
      17,    63,    67,    12,    14,     4,     5,     6,     7,     8,
      34,    11,    13,    15,    13,    11,    17,    13,    63,    67,
      69,    69,    70,    70,    70,    53,    16,    54,     9,    67,
      13,    15,    55,    49,    10,    17,    19,    21,    22,    23,
      32,    45,    46,    54,    56,    57,    58,    59,    60,    61,
      62,    67,    73,    12,    12,    10,    10,    10,    67,    10,
       9,    64,    65,    66,    68,    64,    10,    67,    13,    24,
      25,    26,    27,    28,    29,    13,    10,    57,    66,    66,
      68,    68,    68,    68,    57,    20,    57
  };

  const signed char
  sysyfParser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    45,    45,
      46,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      49,    50,    50,    51,    52,    52,    52,    53,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    61,    62,    63,
      63,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    73,    73
  };

  const signed char
  sysyfParser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     1,     4,     3,     6,     2,     3,
       1,     4,     3,     6,     3,     1,     0,     2,     3,     2,
       0,     1,     1,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     7,     5,     5,     2,     2,     3,
       1,     1,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     3,     3,     1,     3,     3,     3,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const sysyfParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "END", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN", "SEMICOLON", "COMMA",
  "LPARENTHESE", "RPARENTHESE", "LSQUARE", "RSQUARE", "LBRACE", "RBRACE",
  "CONST", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "EQ", "NEQ", "LT",
  "GT", "LE", "GE", "INT", "FLOAT", "RETURN", "VOID", "IDENTIFIER",
  "INTCONST", "FLOATCONST", "EOL", "COMMENT", "BLANK", "NOT", "$accept",
  "Begin", "CompUnit", "GlobalDecl", "BType", "VarDecl", "VarDefList",
  "VarDef", "InitVal", "FuncCall", "FuncDef", "FuncFParamList",
  "FuncParam", "Block", "BlockItemList", "BlockItem", "Stmt", "RetStmt",
  "IfStmt", "WhileStmt", "BreakStmt", "ContinueStmt", "ExpList", "Cond",
  "EqExp", "RelExp", "Exp", "AddExp", "MulExp", "UnaryExpr", "PrimaryExpr",
  "Number", "LVal", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  sysyfParser::yyrline_[] =
  {
       0,   104,   104,   111,   115,   121,   125,   134,   137,   140,
     145,   152,   160,   164,   170,   176,   183,   190,   200,   204,
     215,   223,   229,   236,   246,   250,   254,   259,   267,   274,
     278,   283,   287,   293,   300,   306,   309,   313,   316,   319,
     322,   325,   330,   335,   342,   348,   355,   362,   367,   372,
     376,   382,   387,   390,   398,   408,   411,   419,   427,   435,
     445,   450,   453,   461,   471,   474,   482,   490,   500,   507,
     514,   517,   522,   525,   528,   533,   539,   547,   552
  };

  void
  sysyfParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  sysyfParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2433 "/home/liereyy/sysyf/code/sysyfParser/build/sysyfParser.cpp"

#line 559 "/home/liereyy/sysyf/code/sysyfParser/grammar/sysyfParser.yy"


// Register errors to the driver:
void yy::sysyfParser::error (const location_type& l,
                          const std::string& m)
{
    driver.error(l, m);
}

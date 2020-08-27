// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 4 "Parser.yy"
 /*** C/C++ Declarations ***/

#include <physical/runtime.h>
#include <physical/calc/Driver.h>
#include <physical/calc/detail/expression/Literal.h>
#include <physical/calc/detail/expression/Function.h>
#include <physical/calc/detail/expression/StringFunction.h>
#include <physical/calc/detail/expression/Power.h>
#include <physical/calc/detail/expression/Negate.h>
#include <physical/calc/detail/expression/Multiply.h>
#include <physical/calc/detail/expression/Divide.h>
#include <physical/calc/detail/expression/Modulo.h>
#include <physical/calc/detail/expression/Add.h>
#include <physical/calc/detail/expression/Subtract.h>
#include <physical/calc/detail/expression/Assign.h>
#include <physical/calc/detail/expression/VariableLookup.h>

#include <stdio.h>
#include <string>
#include <vector>

namespace runtime { namespace physical { namespace calc { namespace detail {
  void bison_parser_help();

  inline std::string sstrip( const std::string & s );
} } } }


#line 69 "pregen-parser/Parser.cpp"


#include "Parser.hpp"

// Second part of user prologue.
#line 135 "Parser.yy"


#include <physical/calc/detail/Scanner.h>

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 87 "pregen-parser/Parser.cpp"



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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 52 "Parser.yy"
namespace runtime { namespace physical { namespace calc { namespace detail {
#line 180 "pregen-parser/Parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
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


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
      case 5: // "string"
#line 120 "Parser.yy"
                    { delete (yysym.value.stringVal); }
#line 424 "pregen-parser/Parser.cpp"
        break;

      case 6: // "identifier"
#line 120 "Parser.yy"
                    { delete (yysym.value.stringVal); }
#line 430 "pregen-parser/Parser.cpp"
        break;

      case 25: // literal
#line 121 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 436 "pregen-parser/Parser.cpp"
        break;

      case 26: // variable
#line 121 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 442 "pregen-parser/Parser.cpp"
        break;

      case 27: // expr_list
#line 124 "Parser.yy"
                    {
  while ( !(yysym.value.nodeVector)->empty() ) {
    delete (yysym.value.nodeVector)->back();
    (yysym.value.nodeVector)->pop_back();
  }
  
  delete (yysym.value.nodeVector);
}
#line 455 "pregen-parser/Parser.cpp"
        break;

      case 28: // string_list
#line 123 "Parser.yy"
                    { delete (yysym.value.stringVector); }
#line 461 "pregen-parser/Parser.cpp"
        break;

      case 29: // function
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 467 "pregen-parser/Parser.cpp"
        break;

      case 30: // atomexpr
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 473 "pregen-parser/Parser.cpp"
        break;

      case 31: // powexpr
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 479 "pregen-parser/Parser.cpp"
        break;

      case 32: // factor
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 485 "pregen-parser/Parser.cpp"
        break;

      case 33: // term
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 491 "pregen-parser/Parser.cpp"
        break;

      case 34: // expr
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 497 "pregen-parser/Parser.cpp"
        break;

      case 35: // assignment
#line 122 "Parser.yy"
                    { delete (yysym.value.calcnode); }
#line 503 "pregen-parser/Parser.cpp"
        break;

      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
#line 59 "Parser.yy"
{
  // initialize the initial location object
  yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 648 "pregen-parser/Parser.cpp"


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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

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
  case 2:
#line 152 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Literal((yystack_[0].value.doubleVal));
      }
#line 777 "pregen-parser/Parser.cpp"
    break;

  case 3:
#line 157 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::VariableLookup(driver.symbols, *(yystack_[0].value.stringVal));
        delete (yystack_[0].value.stringVal);
      }
#line 786 "pregen-parser/Parser.cpp"
    break;

  case 4:
#line 163 "Parser.yy"
      {
        (yylhs.value.nodeVector) = new std::vector< expression::Node * >();
        (yylhs.value.nodeVector)->push_back( (yystack_[0].value.calcnode) );
      }
#line 795 "pregen-parser/Parser.cpp"
    break;

  case 5:
#line 168 "Parser.yy"
      {
        (yylhs.value.nodeVector) = (yystack_[2].value.nodeVector);
        (yylhs.value.nodeVector)->push_back( (yystack_[0].value.calcnode) );
      }
#line 804 "pregen-parser/Parser.cpp"
    break;

  case 6:
#line 174 "Parser.yy"
      {
        (yylhs.value.stringVector) = new std::vector< std::string >();
        (yylhs.value.stringVector)->push_back( sstrip(*(yystack_[0].value.stringVal)) );
        delete (yystack_[0].value.stringVal);
      }
#line 814 "pregen-parser/Parser.cpp"
    break;

  case 7:
#line 180 "Parser.yy"
      {
        (yylhs.value.stringVector) = (yystack_[2].value.stringVector);
        (yylhs.value.stringVector)->push_back( sstrip(*(yystack_[0].value.stringVal)) );
        delete (yystack_[0].value.stringVal);
      }
#line 824 "pregen-parser/Parser.cpp"
    break;

  case 8:
#line 187 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Function(driver.symbols, *(yystack_[2].value.stringVal));
        delete (yystack_[2].value.stringVal);
      }
#line 833 "pregen-parser/Parser.cpp"
    break;

  case 9:
#line 192 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Function(driver.symbols, *(yystack_[3].value.stringVal), *(yystack_[1].value.nodeVector));
        delete (yystack_[3].value.stringVal);
        delete (yystack_[1].value.nodeVector);
      }
#line 843 "pregen-parser/Parser.cpp"
    break;

  case 10:
#line 198 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::StringFunction(driver.symbols, *(yystack_[3].value.stringVal), *(yystack_[1].value.stringVector));
        delete (yystack_[3].value.stringVal);
        delete (yystack_[1].value.stringVector);
      }
#line 853 "pregen-parser/Parser.cpp"
    break;

  case 11:
#line 205 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 861 "pregen-parser/Parser.cpp"
    break;

  case 12:
#line 209 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 869 "pregen-parser/Parser.cpp"
    break;

  case 13:
#line 213 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[1].value.calcnode);
      }
#line 877 "pregen-parser/Parser.cpp"
    break;

  case 14:
#line 217 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 885 "pregen-parser/Parser.cpp"
    break;

  case 15:
#line 222 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 893 "pregen-parser/Parser.cpp"
    break;

  case 16:
#line 226 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Power((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 901 "pregen-parser/Parser.cpp"
    break;

  case 17:
#line 231 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 909 "pregen-parser/Parser.cpp"
    break;

  case 18:
#line 235 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 917 "pregen-parser/Parser.cpp"
    break;

  case 19:
#line 239 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Negate((yystack_[0].value.calcnode));
      }
#line 925 "pregen-parser/Parser.cpp"
    break;

  case 20:
#line 244 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 933 "pregen-parser/Parser.cpp"
    break;

  case 21:
#line 248 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Multiply((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 941 "pregen-parser/Parser.cpp"
    break;

  case 22:
#line 252 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Divide((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 949 "pregen-parser/Parser.cpp"
    break;

  case 23:
#line 256 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Modulo((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 957 "pregen-parser/Parser.cpp"
    break;

  case 24:
#line 261 "Parser.yy"
      {
        (yylhs.value.calcnode) = (yystack_[0].value.calcnode);
      }
#line 965 "pregen-parser/Parser.cpp"
    break;

  case 25:
#line 265 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Add((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 973 "pregen-parser/Parser.cpp"
    break;

  case 26:
#line 269 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Subtract((yystack_[2].value.calcnode), (yystack_[0].value.calcnode));
      }
#line 981 "pregen-parser/Parser.cpp"
    break;

  case 27:
#line 274 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Assign(driver.symbols, *(yystack_[2].value.stringVal), (yystack_[0].value.calcnode));
        delete (yystack_[2].value.stringVal);
      }
#line 990 "pregen-parser/Parser.cpp"
    break;

  case 28:
#line 279 "Parser.yy"
      {
        (yylhs.value.calcnode) = new expression::Assign(driver.symbols, *(yystack_[2].value.stringVal), (yystack_[0].value.calcnode));
        delete (yystack_[2].value.stringVal);
      }
#line 999 "pregen-parser/Parser.cpp"
    break;

  case 29:
#line 285 "Parser.yy"
      {
        driver.dump( std::cout );
        delete (yystack_[0].value.stringVal);
      }
#line 1008 "pregen-parser/Parser.cpp"
    break;

  case 30:
#line 290 "Parser.yy"
      { /* e.g. dump constants */
        enum symbol::TYPE sym_type = symbol::UNDEFINED;
        if      ( (*(yystack_[0].value.stringVal)) == "constants" )
            sym_type = symbol::CONSTANT;
        else if ( (*(yystack_[0].value.stringVal)) == "variables" )
            sym_type = symbol::VARIABLE;
        else if ( (*(yystack_[0].value.stringVal)) == "functions" )
            sym_type = symbol::FUNCTION;

        driver.dump( std::cout, sym_type );

        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);
      }
#line 1027 "pregen-parser/Parser.cpp"
    break;

  case 31:
#line 306 "Parser.yy"
      { /* e.g.  set output pretty */
        bool success = false;
        if (*(yystack_[1].value.stringVal) == "output") {
          success = true;
          if        (*(yystack_[0].value.stringVal) == "pretty") {
            Quantity::setPrintMode(Quantity::PRETTY_PRINT);
          } else if (*(yystack_[0].value.stringVal) == "math") {
            Quantity::setPrintMode(Quantity::MATH_PRINT);
          } else if (*(yystack_[0].value.stringVal) == "latex") {
            Quantity::setPrintMode(Quantity::LATEX_PRINT);
          } else if (*(yystack_[0].value.stringVal) == "latex::oneline") {
            Quantity::setPrintMode(Quantity::LATEX_ONELINE_PRINT);
          } else if (*(yystack_[0].value.stringVal) == "ugly") {
            Quantity::setPrintMode(Quantity::UGLY_PRINT);
          } else
            success = false;
        }

        delete (yystack_[2].value.stringVal);
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);

        if ( !success ) {
          error(yyla.location, "invalid set command " );
          YYERROR;
        }
      }
#line 1059 "pregen-parser/Parser.cpp"
    break;

  case 32:
#line 335 "Parser.yy"
      { /* e.g.  from physical::unit import * */
        bool success = true;
        if ( *(yystack_[1].value.stringVal) == "import" )
          symbol::import( driver.symbols, *(yystack_[2].value.stringVal), "*" );
        else if ( *(yystack_[1].value.stringVal) == "clear" )
          symbol::clear(driver.symbols, *(yystack_[2].value.stringVal), "*" );
        else
          success = false;

        delete (yystack_[3].value.stringVal);
        delete (yystack_[2].value.stringVal);
        delete (yystack_[1].value.stringVal);

        if ( !success ) {
          error(yyla.location, "invalid from command " );
          YYERROR;
        }
      }
#line 1082 "pregen-parser/Parser.cpp"
    break;

  case 33:
#line 354 "Parser.yy"
      { /* e.g.  from physical::unit import * to myunits */
        bool success = true;
        if ( *(yystack_[3].value.stringVal) == "import" && *(yystack_[1].value.stringVal) == "to" )
          symbol::import( driver.symbols, *(yystack_[4].value.stringVal), "*", *(yystack_[0].value.stringVal) );
        else
          success = false;

        delete (yystack_[5].value.stringVal);
        delete (yystack_[4].value.stringVal);
        delete (yystack_[3].value.stringVal);
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);

        if ( !success ) {
          error(yyla.location, "invalid from command " );
          YYERROR;
        }
      }
#line 1105 "pregen-parser/Parser.cpp"
    break;

  case 34:
#line 373 "Parser.yy"
      { /* e.g.  from physical import 'element::.*' */
        bool success = true;
        if ( *(yystack_[1].value.stringVal) == "import" )
          symbol::import( driver.symbols, *(yystack_[2].value.stringVal), sstrip(*(yystack_[0].value.stringVal)) );
        else if ( *(yystack_[1].value.stringVal) == "clear" )
          symbol::clear(driver.symbols, *(yystack_[2].value.stringVal), sstrip(*(yystack_[0].value.stringVal)) );
        else
          success = false;

        delete (yystack_[3].value.stringVal);
        delete (yystack_[2].value.stringVal);
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);

        if ( !success ) {
          error(yyla.location, "invalid from command " );
          YYERROR;
        }
      }
#line 1129 "pregen-parser/Parser.cpp"
    break;

  case 35:
#line 393 "Parser.yy"
      { /* e.g.  from physical::unit import 'element::.*' to myelements */
        bool success = true;
        if ( *(yystack_[3].value.stringVal) == "import" && *(yystack_[1].value.stringVal) == "to" )
          symbol::import( driver.symbols, *(yystack_[4].value.stringVal), sstrip(*(yystack_[2].value.stringVal)), *(yystack_[0].value.stringVal) );
        else
          success = false;

        delete (yystack_[5].value.stringVal);
        delete (yystack_[4].value.stringVal);
        delete (yystack_[3].value.stringVal);
        delete (yystack_[2].value.stringVal);
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);

        if ( !success ) {
          error(yyla.location, "invalid from command " );
          YYERROR;
        }
      }
#line 1153 "pregen-parser/Parser.cpp"
    break;

  case 36:
#line 414 "Parser.yy"
      { /* e.g. clear * */
        symbol::clear( driver.symbols, "", "*" );
        delete (yystack_[1].value.stringVal);
      }
#line 1162 "pregen-parser/Parser.cpp"
    break;

  case 37:
#line 419 "Parser.yy"
      { /* e.g. clear physcal::unit::m */
        symbol::clear( driver.symbols, *(yystack_[0].value.stringVal), "" );
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);
      }
#line 1172 "pregen-parser/Parser.cpp"
    break;

  case 38:
#line 425 "Parser.yy"
      { /* e.g. clear 'physical::element::.*' */
        symbol::clear( driver.symbols, "", sstrip(*(yystack_[0].value.stringVal)) );
        delete (yystack_[1].value.stringVal);
        delete (yystack_[0].value.stringVal);
      }
#line 1182 "pregen-parser/Parser.cpp"
    break;

  case 39:
#line 432 "Parser.yy"
      {
        std::cerr << "just hit CTL-C!" << std::endl;
        delete (yystack_[0].value.stringVal);
        /* std::exit(EXIT_SUCCESS); */
      }
#line 1192 "pregen-parser/Parser.cpp"
    break;

  case 42:
#line 440 "Parser.yy"
      {
        bison_parser_help();
        delete (yystack_[0].value.stringVal);
      }
#line 1201 "pregen-parser/Parser.cpp"
    break;

  case 52:
#line 459 "Parser.yy"
      {
        driver.expressions.push_back((yystack_[1].value.calcnode));
      }
#line 1209 "pregen-parser/Parser.cpp"
    break;

  case 53:
#line 463 "Parser.yy"
      {
        driver.expressions.push_back((yystack_[1].value.calcnode));
      }
#line 1217 "pregen-parser/Parser.cpp"
    break;


#line 1221 "pregen-parser/Parser.cpp"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -15;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -15,     1,   -15,   -15,   -15,    42,   -15,    -4,    19,   -15,
      37,    22,    17,    17,    38,   -15,   -15,   -15,   -15,     5,
     -15,   -15,    51,    16,     3,   -15,   -15,   -15,   -15,     3,
     -15,    27,    49,   -15,    43,    48,   -15,   -15,   -15,    41,
     -15,   -15,    45,    38,    38,    38,    38,   -15,    38,    38,
     -15,   -15,   -15,   -15,   -15,   -15,    59,    60,    56,    56,
     -15,   -15,    33,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
      38,   -15,    66,   -15,    77,    78,    56,   -15,    79,    80,
     -15,   -15
  };

  const signed char
  Parser::yydefact_[] =
  {
      49,     0,     1,    46,     2,     3,    39,    29,     0,    42,
       0,     0,     0,     0,     0,    45,    11,    12,    14,    15,
      17,    20,    24,     0,     0,    40,    41,    43,    44,     0,
      50,     0,     0,    30,     0,     0,    38,    37,    36,     3,
      19,    18,     0,     0,     0,     0,     0,    48,     0,     0,
      47,    53,    52,    51,     6,     8,     0,     0,     4,    27,
      28,    31,     0,    13,    16,    21,    22,    23,    26,    25,
       0,     9,     0,    10,    34,    32,     5,     7,     0,     0,
      35,    33
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -15,   -15,   -15,   -15,   -15,   -15,   -15,    69,    30,   -15,
     -14,    55,   -15,   -15,   -15,   -15,   -15,    87,    21,   -15
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    16,    17,    56,    57,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    50,    51,     1
  };

  const signed char
  Parser::yytable_[] =
  {
      42,     2,    33,    47,     3,     4,     3,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    47,    58,    59,     3,
      14,     4,    43,    39,    15,    34,    15,    36,    37,    48,
      49,     4,    54,    39,    68,    69,    14,    38,    74,    15,
      12,    13,     4,    35,    39,    52,    14,    55,    75,    61,
      53,    12,    13,     4,    62,     5,    76,    14,    48,    49,
      31,    31,    12,    13,    32,    63,    44,    45,    14,    48,
      49,    77,    46,    64,    65,    66,    67,    70,    72,    71,
      73,    40,    41,    78,    79,    80,    81,    60,    30
  };

  const signed char
  Parser::yycheck_[] =
  {
      14,     0,     6,     0,     3,     4,     3,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    31,    32,     3,
      19,     4,    17,     6,    23,     6,    23,     5,     6,    13,
      14,     4,     5,     6,    48,    49,    19,    15,     5,    23,
      13,    14,     4,     6,     6,    24,    19,    20,    15,     6,
      29,    13,    14,     4,     6,     6,    70,    19,    13,    14,
      19,    19,    13,    14,    22,    20,    15,    16,    19,    13,
      14,     5,    21,    43,    44,    45,    46,    18,    18,    20,
      20,    12,    13,     6,     6,     6,     6,    32,     1
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    43,     0,     3,     4,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    19,    23,    25,    26,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    19,    22,     6,     6,     6,     5,     6,    15,     6,
      31,    31,    34,    17,    15,    16,    21,     0,    13,    14,
      41,    42,    42,    42,     5,    20,    27,    28,    34,    34,
      35,     6,     6,    20,    32,    32,    32,    32,    34,    34,
      18,    20,    18,    20,     5,    15,    34,     5,     6,     6,
       6,     6
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    24,    25,    26,    27,    27,    28,    28,    29,    29,
      29,    30,    30,    30,    30,    31,    31,    32,    32,    32,
      33,    33,    33,    33,    34,    34,    34,    35,    35,    36,
      36,    37,    38,    38,    38,    38,    39,    39,    39,    40,
      40,    40,    40,    40,    40,    41,    41,    42,    42,    43,
      43,    43,    43,    43
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     3,     3,     4,
       4,     1,     1,     3,     1,     1,     3,     1,     2,     2,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       2,     3,     4,     6,     4,     6,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     3,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"double\"", "\"string\"", "\"identifier\"", "\"quit keyword\"",
  "\"dump keyword\"", "\"set keyword\"", "\"help keyword\"",
  "\"from keyword\"", "\"clear keyword\"", "'-'", "'+'", "'*'", "'/'",
  "'^'", "','", "'('", "')'", "'%'", "'='", "';'", "$accept", "literal",
  "variable", "expr_list", "string_list", "function", "atomexpr",
  "powexpr", "factor", "term", "expr", "assignment", "dump_command",
  "set_command", "from_command", "clear_command", "command", "eos", "eoa",
  "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   151,   151,   156,   162,   167,   173,   179,   186,   191,
     197,   204,   208,   212,   216,   221,   225,   230,   234,   238,
     243,   247,   251,   255,   260,   264,   268,   273,   278,   284,
     289,   305,   334,   353,   372,   392,   413,   418,   424,   431,
     437,   438,   439,   444,   445,   448,   449,   452,   453,   455,
     456,   457,   458,   462
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
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

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
      19,    20,    15,    14,    18,    13,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    17,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12
    };
    const int user_token_number_max_ = 267;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 52 "Parser.yy"
} } } } // runtime::physical::calc::detail
#line 1710 "pregen-parser/Parser.cpp"

#line 469 "Parser.yy"
 /*** Additional Code ***/

namespace runtime { namespace physical { namespace calc { namespace detail {
  void Parser::error( const Parser::location_type& l,
                               const std::string& m ) {
    driver.error(l, m);
  }

  void bison_parser_help() {
    std::cerr <<
     "Commands:\n"
     "\tquit                             : quit (of course)\n"
     "\tdump                             : dumps the list of all known symbols\n"
     "\tdump constants                   : dumps the list of constant symbols\n"
     "\tdump variables                   : dumps the list of variable symbols\n"
     "\tdump functions                   : dumps the list of function symbols\n"
     "\tset output pretty                : sets the output to mimic GNU units output (default)\n"
     "\tset output math                  : sets the output to be mathematically correct\n"
     "\tset output latex                 : sets the output to formatted for latex math mode using \\frac{}{}\n"
     "\tset output latex::oneline        : sets the output to formatted for latex math mode on one line\n"
     "\tset output ugly                  : sets the output to demonstrate the underlying units structure\n"
     "\thelp                             : show this message\n"
     "\tfrom <prefix> import {*|'regex'} [to <new_prefix>]\n"
     "\t                                 : copy symbols from <prefix> into a new \n"
     "\t                                   namespace.  If the optional 'to <new_prefix>'\n"
     "\t                                   is not given, the root namespace will be targeted.\n"
     "\t                                   The symbols that are copied can be controlled further\n"
     "\t                                   with a regular expression for the\n"
     "\t                                   remaining portion of the symbol name\n"
     "\tclear {*|'regex'}                : remove particular symbols from memory\n"
     "\tfrom <prefix> clear {*|'regex'}  : remove symbols that are in the <prefix>\n"
     "\t                                   namespace and match the regular\n"
     "\t                                   expression string regex\n"
     "\n"
     "Operators supported:\n"
     "\t<var-name> = <expression>        : Level 0 precedence (lowest)\n"
     "\t+, -                             : Level 1 precedence\n"
     "\t*, /, %                          : Level 2 precedence\n"
     "\t^                                : Level 3 precedence\n"
     "\n"
     "non-math builtin functions supported:\n"
     "\tnew_unit('unit-name')            : Creates a new fundamental unit called 'unit-name.'\n"
     "\t                                   This builtin function returns an\n"
     "\t                                   expression that can be used like\n"
     "\t                                   any other expression.\n"
     "\n"
     "Additional information:\n"
     "\tUnary functions are supported (such as sin, cos, tan, exp, ...)\n"
     "\tAssignment to variables is supported, such as: v = 10*m/s\n"
     "\t(Note:  CONSTANT symbol names will not allow reassignment)\n"
              << std::flush;
  }

  /** This function strips off the leading and trailing quotes.  */
  inline std::string sstrip( const std::string & s ) {
    return s.substr(1, s.size()-2);
  }

} } } }


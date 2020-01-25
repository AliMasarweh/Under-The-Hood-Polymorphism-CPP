//
// Created by ali-masa on 1/25/20.
//

#include "cpp2c_polymorphism_virtual_tables_c.h"
#include "../../../../usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"

void TEXT_FORMATTER__VTABLE_init_(){
    TEXT_FORMATTER__VTABLE.dtor = TextFormat__dtorTextFormatter;
    TEXT_FORMATTER__VTABLE.print = NULL;
}

void DEFAULT_TEXT_FORMATTER__VTABLE_init_(){
    DEFAULT_TEXT_FORMATTER__VTABLE.dtor = DefaultTextFormat__dtorDefaultTextFormatter_0;
    DEFAULT_TEXT_FORMATTER__VTABLE.print = DefaultTextFormat__print_s_1;
}

void PRE_POST_FIXER__VTABLE_init_(){
    PRE_POST_FIXER__VTABLE.dtor = PrePostFixer__dtorPrePostFixer_0;
    PRE_POST_FIXER__VTABLE.print = kPrePostFixer__print_s_1;
    PRE_POST_FIXER__VTABLE.getDefaultSymbol = PrePostFixer__getDefaultSymbol_0;
    PRE_POST_FIXER__VTABLE.print_l_c = kPrePostFixer__print_l_c_2;
}

void PRE_POST_DOLLAR_FIXER__VTABLE_init_(){
    PRE_POST_DOLLAR_FIXER__VTABLE.dtor = PrePostDollarFixer__dtorPrePostDollarFixer_0;
    PRE_POST_DOLLAR_FIXER__VTABLE.print = kPrePostFixer__print_s_1;
    PRE_POST_DOLLAR_FIXER__VTABLE.getDefaultSymbol = kPrePostDollarFixer__getDefaultSymbol_0;
    PRE_POST_DOLLAR_FIXER__VTABLE.print_l_c = kPrePostDollarFixer__print_l_c_2;
}

void PRE_POST_HASH_FIXER__VTABLE_init_(){
    PRE_POST_HASH_FIXER__VTABLE.dtor = PrePostHashFixer__dtorPrePostHashFixer_0;
    PRE_POST_HASH_FIXER__VTABLE.print = kPrePostFixer__print_s_1;
    PRE_POST_HASH_FIXER__VTABLE.getDefaultSymbol = kPrePostHashFixer__getDefaultSymbol_0;
    PRE_POST_HASH_FIXER__VTABLE.print_l_c = kPrePostHashFixer__print_l_c_2;
}

void PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE_init_(){
    PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE.dtor = PrePostFloatDollarFixer__dtorPrePostFloatDollarFixer_0;
    PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE.print = kPrePostFixer__print_s_1;
    PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE.getDefaultSymbol = kPrePostFloatDollarFixer__getDefaultSymbol_0;
    PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE.print_l_c = kPrePostDollarFixer__print_i_c_2;
}

void PRE_POST_CHECKER__VTABLE_init_(){
    PRE_POST_CHECKER__VTABLE.dtor = PrePostFloatDollarFixer__dtorPrePostFloatDollarFixer_0;
    PRE_POST_CHECKER__VTABLE.print = kPrePostFixer__print_s_1;
    PRE_POST_CHECKER__VTABLE.getDefaultSymbol = kPrePostFloatDollarFixer__getDefaultSymbol_0;
    PRE_POST_CHECKER__VTABLE.print_l_c = kPrePostDollarFixer__print_i_c_2;
}

void MULTIPLIER__VTABLE_init_(){
    MULTIPLIER__VTABLE.dtor = Multiplier__dtorMultiplier;
    MULTIPLIER__VTABLE.print = Multiplier__print;
}

void init_all()
{
    TEXT_FORMATTER__VTABLE_init_();
    DEFAULT_TEXT_FORMATTER__VTABLE_init_();
    PRE_POST_FIXER__VTABLE_init_();
    PRE_POST_DOLLAR_FIXER__VTABLE_init_();
    PRE_POST_HASH_FIXER__VTABLE_init_();
    PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE_init_();
    PRE_POST_CHECKER__VTABLE_init_();
    MULTIPLIER__VTABLE_init_();
}
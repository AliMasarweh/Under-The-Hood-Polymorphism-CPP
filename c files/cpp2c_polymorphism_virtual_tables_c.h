//
// Created by ali-masa on 1/25/20.
//

#ifndef TRANSLATOR_CPP2C_POLYMORPHISM_VIRTUAL_TABLES_C_H
#define TRANSLATOR_CPP2C_POLYMORPHISM_VIRTUAL_TABLES_C_H

#include <stddef.h>
#include "cpp2c_polymorphism_defs_c.h"


/* Text formatter virtual table*/
struct TEXT_FORMATTER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
}TEXT_FORMATTER__VTABLE;

void TEXT_FORMATTER__VTABLE_init_();

/* The default text formatter table */
struct DEFAULT_TEXT_FORMATTER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
}DEFAULT_TEXT_FORMATTER__VTABLE;

void DEFAULT_TEXT_FORMATTER__VTABLE_init_();

/* Pre & Post fixer table*/
struct PRE_POST_FIXER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
    char (*getDefaultSymbol)(const PrePostFixer * const);
    void (*print_l_c)(const PrePostFixer * const, long num,char symbol)
}PRE_POST_FIXER__VTABLE;

void PRE_POST_FIXER__VTABLE_init_();

/* Pre & Post of Dollar fixer table*/
struct PRE_POST_DOLLAR_FIXER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
    char (*getDefaultSymbol)(const PrePostFixer * const);
    void (*print_l_c)(const PrePostFixer * const, long num,char symbol)
}PRE_POST_DOLLAR_FIXER__VTABLE;

void PRE_POST_DOLLAR_FIXER__VTABLE_init_();

/* Pre & Post of Hash fixer table*/
struct PRE_POST_HASH_FIXER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
    char (*getDefaultSymbol)(const PrePostFixer * const);
    void (*print_l_c)(const PrePostFixer * const, long num,char symbol)
}PRE_POST_HASH_FIXER__VTABLE;

void PRE_POST_HASH_FIXER__VTABLE_init_();

/* Pre & Post of Float Dollar fixer table*/
struct PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
    char (*getDefaultSymbol)(const PrePostFixer * const);
    void (*print_l_c)(const PrePostFixer * const, long num,char symbol)
}PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE;

void PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE_init_();

/* Pre & Post of Float Dollar fixer table*/
struct PRE_POST_CHECKER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
    char (*getDefaultSymbol)(const PrePostFixer * const);
    void (*print_l_c)(const PrePostFixer * const, long num,char symbol)
}PRE_POST_CHECKER__VTABLE;

void PRE_POST_CHECKER__VTABLE_init_();

/* The default text formatter table */
struct MULTIPLIER__VTABLE{
    void (*dtor)(void*);
    void (*print)(const char*);
}MULTIPLIER__VTABLE;

void MULTIPLIER__VTABLE_init_();

void init_all();

#endif //TRANSLATOR_CPP2C_POLYMORPHISM_VIRTUAL_TABLES_C_H

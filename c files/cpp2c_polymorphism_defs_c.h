//
// Created by ali-masa on 1/24/20.
//

#ifndef TRANSLATOR_CPP2C_POLYMORPHISM_DEFS_C_H
#define TRANSLATOR_CPP2C_POLYMORPHISM_DEFS_C_H


#include <stdio.h>

#define printFunc(fname) printf("%-60s | ", fname)

//// TextFormatter ////////////

typedef struct TextFormatter
{
    void* vtpntr;
    /*
    virtual ~TextFormatter() { };
    virtual void print(const char* text) const = 0;
     */
}TextFormatter;

void TextFormat__dtorTextFormatter(TextFormatter* const this);
void TextFormat__print(const char* text);

//// DefaultTextFormatter ////////////
typedef struct DefaultTextFormat__Ider DDefaultTextFormat__Ider;
struct DefaultTextFormat__Ider
{
    char dummy;
};

extern int DefaultTextFormat__Ider__next_id;
#define DefaultTextFormat__Ider__getId_0() (++DefaultTextFormat__Ider__next_id)
/*static int DefaultTextFormat__Ider__getId_0() {return ++DTF__Ider__next_id;}*/

typedef struct DefaultTextFormatter{
    TextFormatter __base;
/*

    struct DefaultTextFormat__Ider
    {
        static int next_id;
        static int getId() { return next_id++; }
    };
*/

    int id;
}DefaultTextFormatter;

DefaultTextFormatter* generateFormatterArray();

void DefaultTextFormat__DefaultTextFormatter_0(DefaultTextFormatter * const);
void DefaultTextFormat__DefaultTextFormatter_kDTFkP_1(DefaultTextFormatter * const,
        const DefaultTextFormatter* const);
void DefaultTextFormat__dtorDefaultTextFormatter_0(DefaultTextFormatter* const);
DefaultTextFormatter* DefaultTextFormat__op_assign_kDTFkP_1(DefaultTextFormatter * const,
        const DefaultTextFormatter * const);
void DefaultTextFormat__dtorDefaultTextFormatter(DefaultTextFormatter * const);

/*virtual*/void DefaultTextFormat__print_s_1(DefaultTextFormatter * const, const char* text);

//// PrePostFixer ////////////

typedef struct PrePostFixer
{
    DefaultTextFormatter __base;
    const char* pre;
    const char* post;
}PrePostFixer;

void PrePostFixer__PrePostFixer_s_s_2(PrePostFixer * const, const char* prefix, const char* postfix);
void PrePostFixer__dtorPrePostFixer_0(PrePostFixer * const);

/*virtual*/ void kPrePostFixer__print_s_1(const PrePostFixer * const, const char* text);
/*virtual*/ void kPrePostFixer__print_l_c_2(const PrePostFixer * const, long num,
        char symbol /*= '\0'*/);

/*virtual*/ char PrePostFixer__getDefaultSymbol_0(const PrePostFixer * const);

/*const char* kPrePostFixer__getPrefix_0(const PrePostFixer * const);
const char* kPrePostFixer__getPostfix_0(const PrePostFixer * const);*/

void kPrePostFixer__print_num_l_1(const PrePostFixer * const, long num);
/*void kPrePostFixer__print_num_l_c_2(const PrePostFixer * const, long num, char symbol);*/
//// PrePostFixer Defs ////////////

#define kPrePostFixer__getPrefix_0(this) this->pre
/*const char* kPrePostFixer__getPrefix_0(const PrePostFixer * const this)
{
    return this->pre;
}*/

#define kPrePostFixer__getPostfix_0(this) this->post

/*const char* kPrePostFixer__getPostfix_0(const PrePostFixer * const this)
{
    return this->post;
}*/

#define kPrePostFixer__print_num_l_1(this, num) printFunc("[PrePostFixer::print_num(long)]"); printf("%s%ld%s\n", this->pre, num, this->post)

/*void kPrePostFixer__print_num_l_1(const PrePostFixer * const this, long num)
{
printFunc("[PrePostFixer::print_num(long)]");
printf("%s%ld%s\n", this->pre, num, this->post);
}*/

#define kPrePostFixer__print_num_l_c_2(this, num, symbol) printFunc("[PrePostFixer::print_num(long, char)]"); printf("%s%c%ld%s\n", this->pre, symbol, num, this->post)


//// PrePostDollarFixer ////////////

typedef struct PrePostDollarFixer
{
    PrePostFixer __base;

}PrePostDollarFixer;
extern const char PrePostDollarFixer__DEFAULT_SYMBOL;

void PrePostDollarFixer__PrePostDollarFixer_s_s_2(PrePostDollarFixer * const, const char* prefix,
        const char* postfix);
void PrePostDollarFixer__PrePostDollarFixer_kPrePostHashFixerkP_1(PrePostDollarFixer * const,
        const PrePostDollarFixer* const other);
void PrePostDollarFixer__dtorPrePostDollarFixer_0(PrePostDollarFixer * const);

void kPrePostDollarFixer__print_i_c_2(const PrePostDollarFixer * const, int num,
        char symbol /*= DEFAULT_SYMBOL*/);
void kPrePostDollarFixer__print_l_c_2(const PrePostDollarFixer * const, long num,
        char symbol /*= DEFAULT_SYMBOL*/);
void kPrePostDollarFixer__print_d_c_2(const PrePostDollarFixer * const, double num,
        char symbol /*= DEFAULT_SYMBOL*/);
char kPrePostDollarFixer__getDefaultSymbol_0(const PrePostDollarFixer * const);
//// PrePostDollarFixer Defs ////////////

//// PrePostHashFixer ////////////

typedef struct PrePostHashFixer
{
    PrePostDollarFixer __base;
    int precision;
}PrePostHashFixer;
extern const char PrePostHashFixer__DEFAULT_SYMBOL;

void PrePostHashFixer__PrePostHashFixer_i_1(PrePostHashFixer * const, int prc /*= 4*/);
void PrePostHashFixer__dtorPrePostHashFixer_0(PrePostHashFixer * const);

void kPrePostHashFixer__print_i_c_2(const PrePostHashFixer * const, int num,
        char symbol /*= DEFAULT_SYMBOL*/);
void kPrePostHashFixer__print_l_c_2(const PrePostHashFixer * const, long num,
        char symbol /*= DEFAULT_SYMBOL*/);
void kPrePostHashFixer__print_d_c_2(const PrePostHashFixer * const, double num,
        char symbol /*= DEFAULT_SYMBOL*/);
char kPrePostHashFixer__getDefaultSymbol_0(const PrePostHashFixer * const);
//// PrePostHashFixer Defs ////////////
/*
#define kPrePostHashFixer__print_d_c_2(this, num, symbol) printFunc("[PrePostHashFixer::print(double, char)]"); printf("%s[%c%.*f]%s\n", kPrePostFixer__getPrefix_0((&this->__base.__base)), symbol, this->precision, num, kPPF__getPostfix_0((&this->__base.__base)))
*/

//// PrePostFloatDollarFixer ////////////

typedef struct PrePostFloatDollarFixer
{
    PrePostDollarFixer __base;
}PrePostFloatDollarFixer;
extern const char PrePostFloatDollarFixer__DEFAULT_SYMBOL;

void PrePostFloatDollarFixer__PrePostFloatDollarFixer_s_s_2(PrePostFloatDollarFixer* const,
        const char* prefix, const char* postfix);
void PrePostFloatDollarFixer__dtorPrePostFloatDollarFixer_0(PrePostFloatDollarFixer* const);
void kPrePostFloatDollarFixer__print_f_1(const PrePostFloatDollarFixer* const, float num);
void kPrePostFloatDollarFixer__print_f_c_2(const PrePostFloatDollarFixer* const, float num, char symbol);
char kPrePostFloatDollarFixer__getDefaultSymbol_0(const PrePostFloatDollarFixer* const);
//// PrePostFloatDollarFixer Defs ////////////

//// PrePostChecker ////////////

typedef struct PrePostChecker
{
    PrePostFloatDollarFixer __base;

}PrePostChecker;

void PrePostChecker__PrePostChecker_0(PrePostChecker * const);
void PrePostChecker__dtorPrePostChecker_0(PrePostChecker * const);

void kPrePostChecker__printThisSymbolUsingFunc_0(PrePostChecker * const);
void kPrePostChecker__printThisSymbolDirectly_0(PrePostChecker * const);
void kPrePostChecker__printDollarSymbolByCastUsingFunc_0(PrePostChecker * const);
void kPrePostChecker__printDollarSymbolByScopeUsingFunc_0(PrePostChecker * const);
void kPrePostChecker__printDollarSymbolByCastDirectly_0(PrePostChecker * const);
void kPrePostChecker__printDollarSymbolByScopeDirectly_0(PrePostChecker * const);

//// Multiplier ////////////

typedef struct Multiplier
{
    DefaultTextFormatter __base;
    int times;
}Multiplier;

void Multiplier__Multiplier_i_1(Multiplier* const, int t /*= 2*/);
void Multiplier__dtorMultiplier(Multiplier* const);

void Multiplier__print(Multiplier* const, const char*);
int Multiplier__getTimes(Multiplier* const);
void Multiplier__setTimes(Multiplier* const, int);


#endif //TRANSLATOR_CPP2C_POLYMORPHISM_DEFS_C_H

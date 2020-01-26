//
// Created by ali-masa on 1/25/20.
//

#include <stdlib.h>
#include "cpp2c_polymorphism_defs_c.h"
#include "cpp2c_polymorphism_virtual_tables_c.h"

int DefaultTextFormat__Ider__next_id = 0;
const char PrePostDollarFixer__DEFAULT_SYMBOL = '$';
const char PrePostHashFixer__DEFAULT_SYMBOL = '#';
const char PrePostFloatDollarFixer__DEFAULT_SYMBOL = '@';

void TextFormat__dtorTextFormatter(TextFormatter* const this){
    this->vtpntr = NULL;
}


void DefaultTextFormat__dtorDefaultTextFormatter_0(DefaultTextFormatter* const this){
    this->__base.vtpntr = &TEXT_FORMATTER__VTABLE;
}

//// DefaultTextFormatter Defs ////////////

void DefaultTextFormat__DefaultTextFormatter_0(DefaultTextFormatter *const this) {
    this->__base.vtpntr = &DEFAULT_TEXT_FORMATTER__VTABLE;
    this->id = DefaultTextFormat__Ider__getId_0();
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n",
           this->id);
}

void DefaultTextFormat__dtorDefaultTextFormatter(DefaultTextFormatter *const this) {
    this->__base.vtpntr = &TEXT_FORMATTER__VTABLE;
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}

void DefaultTextFormat__DefaultTextFormatter_kDTFkP_1(DefaultTextFormatter *const this,
                                        const DefaultTextFormatter *const other) {
    this->__base.vtpntr = &DEFAULT_TEXT_FORMATTER__VTABLE;
    this->id = other->id;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n",
           other->id, this->id);
}

DefaultTextFormatter *DefaultTextFormat__op_assign_kDTFkP_1(DefaultTextFormatter *const this,
                                              const DefaultTextFormatter *const other) {
    this->__base.vtpntr = &DEFAULT_TEXT_FORMATTER__VTABLE;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n",
           other->id, this->id);
    return this;
}

void DefaultTextFormat__print_s_1(DefaultTextFormatter *const this, const char *text) {
    printFunc("[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter *generateFormatterArray() {
    return (DefaultTextFormatter *) malloc(3 * sizeof(DefaultTextFormatter));
}


//// PrePostFixer Defs ////////////

void PrePostFixer__PrePostFixer_s_s_2(PrePostFixer *const this,
                             const char *prefix, const char *postfix) {
    ((TextFormatter*) this)->vtpntr = &PRE_POST_FIXER__VTABLE;
    this->pre = prefix;
    this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void PrePostFixer__dtorPrePostFixer_0(PrePostFixer *const this) {
    ((TextFormatter*) this)->vtpntr = &DEFAULT_TEXT_FORMATTER__VTABLE;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

char PrePostFixer__getDefaultSymbol_0(const PrePostFixer * const this)
{
    return '\0';
}

void kPrePostFixer__print_s_1(const PrePostFixer *const this, const char *text) {
    printFunc("[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}

void kPrePostFixer__print_l_c_2(const PrePostFixer * const this, long num, char symbol /*= '\0'*/)
{
    printFunc("[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol){
        kPrePostFixer__print_num_l_c_2(this, num, symbol);
    }
    else
        kPrePostFixer__print_num_l_1(this, num);
}

/*void kPrePostFixer__print_num_l_c_2(const PrePostFixer * const this, long num, char symbol)
{
    printFunc("[PrePostFixer::print_num(long, char)]");
    printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
}*/

//// PrePostDollarFixer Defs ////////////

void PrePostDollarFixer__PrePostDollarFixer_s_s_2(PrePostDollarFixer *const this, const char *prefix,
                                    const char *postfix) {
    ((TextFormatter*) this)->vtpntr = &PRE_POST_DOLLAR_FIXER__VTABLE;
    PrePostFixer__PrePostFixer_s_s_2(&this->__base, prefix, postfix);
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base)),
           kPrePostFixer__getPostfix_0((&this->__base)));
}

void PrePostDollarFixer__PrePostDollarFixer_kPrePostHashFixerkP_1(PrePostDollarFixer *const this,
                                        const PrePostDollarFixer *const other) {
    ((TextFormatter*) this)->vtpntr = &PRE_POST_DOLLAR_FIXER__VTABLE;
    this->__base = other->__base;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base)),
           kPrePostFixer__getPostfix_0((&this->__base)));
}

void PrePostDollarFixer__dtorPrePostDollarFixer_0(PrePostDollarFixer *const this) {
    ((TextFormatter*) this)->vtpntr = &PRE_POST_FIXER__VTABLE;
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base)),
           kPrePostFixer__getPostfix_0((&this->__base)));
}

void kPrePostDollarFixer__print_i_c_2(const PrePostDollarFixer *const this, int num,
                        char symbol /*= DEFAULT_SYMBOL*/) {
    printFunc("[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    kPrePostFixer__print_l_c_2((&this->__base), (long) num, symbol);
}

void kPrePostDollarFixer__print_l_c_2(const PrePostDollarFixer *const this, long num, char symbol) {
    printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    kPrePostFixer__print_l_c_2((&this->__base), num, symbol);
}

void kPrePostDollarFixer__print_d_c_2(const PrePostDollarFixer *const this, double num, char symbol) {
    printFunc("[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", kPrePostFixer__getPrefix_0((&this->__base)),
           symbol, num, kPrePostFixer__getPostfix_0((&this->__base)));
}

char kPrePostDollarFixer__getDefaultSymbol_0(const PrePostDollarFixer * const this)
{
    return PrePostDollarFixer__DEFAULT_SYMBOL;
}

//// PrePostHashFixer Defs ////////////

void PrePostHashFixer__PrePostHashFixer_i_1(PrePostHashFixer * const this, int prc)
{
    ((TextFormatter*) this)->vtpntr = &PRE_POST_HASH_FIXER__VTABLE;
    PrePostDollarFixer__PrePostDollarFixer_s_s_2(&this->__base, "===> ", " <===");
    this->precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n",
           kPrePostFixer__getPrefix_0((&this->__base.__base)),
           kPrePostFixer__getPostfix_0((&this->__base.__base)),
           this->precision);

    kPrePostDollarFixer__print_d_c_2(this, 9999.9999, kPrePostDollarFixer__getDefaultSymbol_0(this));
}

void PrePostHashFixer__dtorPrePostHashFixer_0(PrePostHashFixer * const this)
{
    ((TextFormatter*) this)->vtpntr = &PRE_POST_DOLLAR_FIXER__VTABLE;
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n",
            kPrePostFixer__getPrefix_0((&this->__base.__base)),
            kPrePostFixer__getPostfix_0((&this->__base.__base)));
}

void kPrePostHashFixer__print_i_c_2(const PrePostHashFixer * const this, int num,
                        char symbol /*= DEFAULT_SYMBOL*/)
{
    printFunc("[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    kPrePostHashFixer__print_d_c_2(this, (double) num, symbol);
}

void kPrePostHashFixer__print_l_c_2(const PrePostHashFixer * const this, long num,
                        char symbol /*= DEFAULT_SYMBOL*/)
{
    printFunc("[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
    kPrePostHashFixer__print_d_c_2(this, (double) num, symbol);
}

void kPrePostHashFixer__print_d_c_2(const PrePostHashFixer * const this, double num, char symbol /*= DEFAULT_SYMBOL*/)
{
    printFunc("[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", kPrePostFixer__getPrefix_0((&this->__base.__base)), symbol,
           this->precision, num, kPrePostFixer__getPostfix_0((&this->__base.__base)));
}

char kPrePostHashFixer__getDefaultSymbol_0(const PrePostHashFixer * const this)
{
    return PrePostHashFixer__DEFAULT_SYMBOL;
}

//// PrePostFloatDollarFixer Defs ////////////

void PrePostFloatDollarFixer__PrePostFloatDollarFixer_s_s_2(PrePostFloatDollarFixer* const this,
                                          const char* prefix, const char* postfix)
{
    ((TextFormatter*) this)->vtpntr = &PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE;
    PrePostDollarFixer__PrePostDollarFixer_s_s_2(&(this->__base), prefix, postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base.__base)),
           kPrePostFixer__getPostfix_0((&this->__base.__base))
           );
}

void PrePostFloatDollarFixer__dtorPrePostFloatDollarFixer_0(PrePostFloatDollarFixer* const this)
{
    ((TextFormatter*) this)->vtpntr = &PRE_POST_DOLLAR_FIXER__VTABLE;
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base.__base)),
           kPrePostFixer__getPostfix_0((&this->__base.__base)));
}

void kPrePostFloatDollarFixer__print_f_1(const PrePostFloatDollarFixer* const this, float num)
{
    printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    kPrePostDollarFixer__print_d_c_2(this, num, kPrePostDollarFixer__getDefaultSymbol_0(this));
}

void kPrePostFloatDollarFixer__print_f_c_2(const PrePostFloatDollarFixer* const this, float num, char symbol)
{
printFunc("[PrePostFloatDollarFixer::print(float, char)]");

printf("%s%c%.2f%s\n",
       kPrePostFixer__getPrefix_0((&this->__base.__base)), symbol, num,
       kPrePostFixer__getPostfix_0((&this->__base.__base))
);
}


char kPrePostFloatDollarFixer__getDefaultSymbol_0(const PrePostFloatDollarFixer* const this)
{
    return PrePostFloatDollarFixer__DEFAULT_SYMBOL;
}

//// PrePostChecker Defs ////////////

void PrePostChecker__PrePostChecker_0(PrePostChecker * const this)
{
    ((TextFormatter*) this)->vtpntr = &PRE_POST_CHECKER__VTABLE;
    PrePostFloatDollarFixer__PrePostFloatDollarFixer_s_s_2(this, "[[[[ ", " ]]]]");
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",
       kPrePostFixer__getPrefix_0((&this->__base.__base.__base)),
       kPrePostFixer__getPostfix_0((&this->__base.__base.__base))
    );
}

void PrePostChecker__dtorPrePostChecker_0(PrePostChecker * const this){
    ((TextFormatter*) this)->vtpntr = &PRE_POST_FLOAT_DOLLAR_FIXER__VTABLE;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",
           kPrePostFixer__getPrefix_0((&this->__base.__base.__base)),
           kPrePostFixer__getPostfix_0((&this->__base.__base.__base)));
}

void kPrePostChecker__printThisSymbolUsingFunc_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

printf("Default symbol is %c\n", kPrePostFloatDollarFixer__getDefaultSymbol_0(this));
}

void kPrePostChecker__printThisSymbolDirectly_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printThisSymbolDirectly()]");

printf("Default symbol is %c\n", PrePostFloatDollarFixer__DEFAULT_SYMBOL);
}

void kPrePostChecker__printDollarSymbolByCastUsingFunc_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

printf("Default symbol is %c\n",
        kPrePostDollarFixer__getDefaultSymbol_0(((PrePostDollarFixer*)(this))));
}

void kPrePostChecker__printDollarSymbolByScopeUsingFunc_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

printf("Default symbol is %c\n", kPrePostDollarFixer__getDefaultSymbol_0(this));
}

void kPrePostChecker__printDollarSymbolByCastDirectly_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

printf("Default symbol is %c\n", PrePostDollarFixer__DEFAULT_SYMBOL);
}

void kPrePostChecker__printDollarSymbolByScopeDirectly_0(PrePostChecker * const this)
{
printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

printf("Default symbol is %c\n", PrePostDollarFixer__DEFAULT_SYMBOL);
}


//// Multiplier Defs ////////////

void Multiplier__print(Multiplier* const this, const char* text)
{
    printFunc("[Multiplier::print(const char*)]");
    for (int i = 0;i<this->times;++i)
        printf("%s", text);
    printf("\n");
}

//// Multiplier Defs ////////////

void Multiplier__Multiplier_i_1(Multiplier* const this, int t)
{
    ((TextFormatter*) this)->vtpntr = &MULTIPLIER__VTABLE;
    this->times = t;
    printf("--- Multiplier CTOR: times = %d\n", this->times);
}

void Multiplier__dtorMultiplier(Multiplier* const this)
{
    ((TextFormatter*) this)->vtpntr = &DEFAULT_TEXT_FORMATTER__VTABLE;
    printf("--- Multiplier DTOR: times = %d\n", this->times);
}

int Multiplier__getTimes(Multiplier* const this)
{
    return this->times;
}

void Multiplier__setTimes(Multiplier* const this, int t)
{
    this->times = t;
}

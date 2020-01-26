//
// Created by ali-masa on 1/25/20.
//

#include <stdlib.h>
#include "cpp2c_polymorphism_defs_c.h"
#include "cpp2c_polymorphism_virtual_tables_c.h"


void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    PrePostFixer__PrePostFixer_s_s_2(&angleBrackets, "<<< ", " >>>");

    char defaultSymbol = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) &angleBrackets)->vtpntr)
            ->getDefaultSymbol(&angleBrackets);

    ((struct TEXT_FORMATTER__VTABLE*)((TextFormatter*)&angleBrackets)->vtpntr)
            ->print(&angleBrackets, "Hello World!");
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&angleBrackets)->vtpntr)
            ->print_l_c(&angleBrackets, -777, defaultSymbol);
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&angleBrackets)->vtpntr)
            ->print_l_c(&angleBrackets, 350, '#');
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&angleBrackets)->vtpntr)
            ->print_l_c(&angleBrackets, (long int)3.14, defaultSymbol);

    printf("\n--- end doPrePostFixer() ---\n\n");
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    PrePostDollarFixer__PrePostDollarFixer_s_s_2(&asterisks,
            "***** ", " *****");

    char defaultSymbol = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) &asterisks)->vtpntr)
            ->getDefaultSymbol(&asterisks);

    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&asterisks)->vtpntr)
            ->print_l_c(&asterisks, -777, defaultSymbol);
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&asterisks)->vtpntr)
            ->print_l_c(&asterisks, 350, '#');
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&asterisks)->vtpntr)
            ->print_l_c(&asterisks, (long int)3.14, defaultSymbol);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    kPrePostChecker__printThisSymbolUsingFunc_0(&check);
    kPrePostChecker__printThisSymbolDirectly_0(&check);
    kPrePostChecker__printDollarSymbolByCastDirectly_0(&check);
    kPrePostChecker__printDollarSymbolByScopeDirectly_0(&check);
    kPrePostChecker__printDollarSymbolByCastUsingFunc_0(&check);
    kPrePostChecker__printDollarSymbolByScopeUsingFunc_0(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    PrePostFloatDollarFixer__PrePostFloatDollarFixer_s_s_2(&hashes,
            "### ", " ###");

    char defaultSymbol = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) &hashes)->vtpntr)
            ->getDefaultSymbol(&hashes);

    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&hashes)->vtpntr)
            ->print_l_c(&hashes, -777, defaultSymbol);
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&hashes)->vtpntr)
            ->print_l_c(&hashes, 350, '#');
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&hashes)->vtpntr)
            ->print_l_c(&hashes, (long int)3.14, defaultSymbol);

    PrePostDollarFixer hashes2;
    PrePostDollarFixer__PrePostDollarFixer_kPrePostHashFixerkP_1(&hashes2, &hashes);

    char defaultSymbol2 = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) &hashes2)->vtpntr)
            ->getDefaultSymbol(&hashes2);

    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&hashes)->vtpntr)
            ->print_l_c(&hashes, 7.5, defaultSymbol);
    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)&hashes)->vtpntr)
            ->print_l_c(&hashes, 100, defaultSymbol);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}

void runAsPrePostFixerRef(const PrePostFixer* const pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    char defaultSymbol2 = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) pp)->vtpntr)
            ->getDefaultSymbol(pp);

    ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*)pp)->vtpntr)
            ->print_l_c(pp, 123, defaultSymbol2);


    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* const pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    char defaultSymbol2 = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) pp)->vtpntr)
            ->getDefaultSymbol(pp);

    ((struct PRE_POST_DOLLAR_FIXER__VTABLE*)((TextFormatter*)pp)->vtpntr)
            ->print_l_c(pp, 123, defaultSymbol2);


    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    char defaultSymbol2 = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) &pp)->vtpntr)
            ->getDefaultSymbol(&pp);

    ((struct PRE_POST_DOLLAR_FIXER__VTABLE*)((TextFormatter*)&pp)->vtpntr)
            ->print_l_c(&pp, 123, defaultSymbol2);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    char defaultSymbol2 = ((struct PRE_POST_FIXER__VTABLE*)((TextFormatter*) pp)->vtpntr)
            ->getDefaultSymbol(pp);

    ((struct PRE_POST_DOLLAR_FIXER__VTABLE*)((TextFormatter*)pp)->vtpntr)
    ->print_l_c(pp, 123, defaultSymbol2);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
    Multiplier__Multiplier_i_1(&m1, 3);
    Multiplier m2;
    Multiplier__Multiplier_i_1(&m2, 5);
    Multiplier m3 = m1;
    Multiplier m4;
    Multiplier__Multiplier_i_1(&m4, m2.times);

    Multiplier__print(&m1, "abc ");
    Multiplier__print(&m2, "abc ");
    Multiplier__print(&m3, "abc ");
    Multiplier__print(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    DefaultTextFormatter formatter1, formatter2, formatter3;
    PrePostDollarFixer__PrePostDollarFixer_s_s_2(&formatter1, "!!! ", " !!!");
    Multiplier__Multiplier_i_1(&formatter2, 4);
    PrePostChecker__PrePostChecker_0(&formatter3);
    DefaultTextFormatter formatters[] =
            {
                    formatter1,
                    formatter2,
                    formatter3
            };

    for (int i = 0; i < 3; ++i)
        ((struct TEXT_FORMATTER__VTABLE*)((TextFormatter*)&formatters[i])->vtpntr)
                ->print(&formatters[i], "Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");

    DefaultTextFormatter *formatter1, *formatter2, *formatter3;

    formatter1 = (DefaultTextFormatter*) malloc(sizeof(PrePostDollarFixer));
    formatter2 = (DefaultTextFormatter*) malloc(sizeof(Multiplier));
    formatter3 = (DefaultTextFormatter*) malloc(sizeof(PrePostChecker));

    PrePostDollarFixer__PrePostDollarFixer_s_s_2(formatter1, "!!! ", " !!!");
    Multiplier__Multiplier_i_1(formatter2, 4);
    PrePostChecker__PrePostChecker_0(formatter3);

    DefaultTextFormatter* pfmt[] =
            {
                    formatter1,
                    formatter2,
                    formatter3
            };

    for (int i = 0; i < 3; ++i)
        ((struct TEXT_FORMATTER__VTABLE*)((TextFormatter*)&pfmt[i])->vtpntr)
                ->print(&pfmt[i], "Hello World!");

    for (int i = 2; i >= 0; --i)
        free(&pfmt[i]);

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();

    for (int i = 0; i < 3; ++i)
        ((struct TEXT_FORMATTER__VTABLE*)((TextFormatter*)&formatters[i])->vtpntr)
                ->print(&formatters[i], "Hello World!");

    for (int i = 2; i >= 0; --i)
        free(&formatters[i]);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    poly_vtables_init_all();
    /* Pre-Main */
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    PrePostHashFixer__PrePostHashFixer_i_1(&hfix, 4);
    runAsPrePostFixerRef(&hfix);
    runAsPrePostDollarFixerRef(&hfix);
    runAsPrePostDollarFixerObj(*((PrePostDollarFixer*) &hfix));
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    /*doFormatterArray();*/
    /*doFormatterPtrs();*/
    /*doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");

    return 0;
}






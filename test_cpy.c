#include <CUnit/Basic.h>
#include <string.h>
#include "cpy.h"


void test_cpy_bin(){
    char src[] = {1,2,3,45,5};
    char dest[10];
    size_t size = strlen(src)+1;
    cpy(dest, src, size);

    for(int i = 0; i < size; i++){
        CU_ASSERT_EQUAL(dest[i],src[i]);
    }

    
}



int run_tests(){
    CU_pSuite pSuite = NULL;

    if(CU_initialize_registry() != CUE_SUCCESS){
        return CU_get_error();
    }

    pSuite = CU_add_suite("test_cpy_suite",0,0);
    if (pSuite == NULL){
        CU_cleanup_registry();
        return CU_get_error();
    }

    if(CU_add_test(pSuite, "test of binary copy", test_cpy_bin) == NULL){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();



}

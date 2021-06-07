/*
 * MODEL-BASED SOFTWARE DESIGN
 * LABORATORY 2 SOLUTION - A.Y. 2020/21
 * 
 * (C) 2021 JACOPO SINI, MASSIMO VIOLANTE - Politecnico di Torino 
 */ 

extern "C"
{
#include "../controller.h"
}
#include <gtest/gtest.h>



TEST(ExampleTests, Extraction)
{
    //EXPECT --> Continue after this line in the case the condition is not true
    //ASSERT --> Do not continue after this line in the case the condition is not true
    fprintf(stderr,"Start of the extraction movement test!\n");
    controller_initialize();
    controller_U.AxelLock_DI = 0U;
    controller_U.Current_A = 0.0F;
    controller_U.Extracted_Pos_Switch_DI = 0U;
    controller_U.Inserted_Pos_Switch_DI = 0U;
    controller_U.Pos_mm = 6.0F;
    controller_step();
    ASSERT_EQ(
        0U,
        controller_Y.Error_DO
    );
    EXPECT_EQ(
        1U,
        controller_Y.Extract_DO
    );
    controller_step();
    EXPECT_EQ(
        1U,
        controller_Y.Extract_DO
    );
    controller_step();
    EXPECT_EQ(
        1U,
        controller_Y.Extract_DO
    );
    controller_U.Extracted_Pos_Switch_DI = 1U;
    controller_step();
    ASSERT_EQ(
        1U, 
        controller_Y.Extract_DO
    ) << "controller_Y.Extract_DO = " << controller_Y.Extract_DO << " The expected value is 0: correct the assert EQ value at line 48!!!\n";
    ASSERT_EQ(
        0U,
        controller_Y.Error_DO
    );
}

TEST(ExampleTests, Insertion)
{
    fprintf(stderr,"Start of the insertion movement test!\n");
    controller_initialize();
    controller_U.AxelLock_DI = 1U;
    controller_U.Current_A = 0.0F;
    controller_U.Extracted_Pos_Switch_DI = 0U;
    controller_U.Inserted_Pos_Switch_DI = 0U;
    controller_U.Pos_mm = 6.0F;
    controller_step();
    ASSERT_EQ(
        0U,
        controller_Y.Error_DO
    );
    EXPECT_EQ(
        1U,
        controller_Y.Insert_DO
    );
    controller_step();
    EXPECT_EQ(
        1U,
        controller_Y.Insert_DO
    );
    controller_step();
    EXPECT_EQ(
        1U,
        controller_Y.Insert_DO
    );
    controller_U.Inserted_Pos_Switch_DI = 1U;
    controller_step();
    ASSERT_EQ(
        0U,
        controller_Y.Insert_DO
    );
    ASSERT_EQ(
        0U,
        controller_Y.Error_DO
    );
}
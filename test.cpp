#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

S21Matrix fill_matrix_example() {
    S21Matrix matrix(5, 5);
    matrix(0, 0) = 1.0;
    matrix(0, 1) = 2.0;
    matrix(0, 2) = 3.0;
    matrix(0, 3) = 4.0;
    matrix(0, 4) = 3.0;
    matrix(1, 0) = 0.0;
    matrix(1, 1) = 4.0;
    matrix(1, 2) = 2.0;
    matrix(1, 3) = 3.0;
    matrix(1, 4) = 2.0;
    matrix(2, 0) = 5.0;
    matrix(2, 1) = 2.0;
    matrix(2, 2) = 1.0;
    matrix(2, 3) = 3.0;
    matrix(2, 4) = 3.0;
    matrix(3, 0) = 5.0;
    matrix(3, 1) = 1.0;
    matrix(3, 2) = 1.0;
    matrix(3, 3) = 3.0;
    matrix(3, 4) = 3.0;
    matrix(4, 0) = 5.0;
    matrix(4, 1) = 2.0;
    matrix(4, 2) = 1.0;
    matrix(4, 3) = 8.0;
    matrix(4, 4) = 3.0;
    return matrix;
}

TEST(MatrixEqualTest, HandlesZeroMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne.sum_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixEqualTest, HandlesCorrectMatrixInput) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo = fill_matrix_example();
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixEqualTest, HandlesMatrixInput) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(5, 5);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, false);
}

TEST(MatrixSumTest, HandlesZeroMatrixInput) {
    S21Matrix matrixOne;
    S21Matrix matrixTwo(3, 3);
    matrixOne.sum_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInput) {
    S21Matrix matrixTwo(5, 5);
    S21Matrix matrixOne = fill_matrix_example();
    matrixTwo.sum_matrix(matrixOne);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSumTest, HandlesMatrixInputCorrect) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo = fill_matrix_example();
    matrixOne.sum_matrix(matrixTwo);
    matrixTwo *= 2;
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesZeroMatrixInput) {
    S21Matrix matrixOne;
    S21Matrix matrixTwo(3, 3);
    matrixOne.sub_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInput) {
    S21Matrix matrixZero(5, 5);
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo = fill_matrix_example();
    matrixOne.sub_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixZero);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesMatrixInputCorrect) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo = fill_matrix_example();
    matrixOne *= 2;
    matrixOne.sub_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTest, HandlesErrorOneMatrixInput) { EXPECT_THROW(S21Matrix matrixOne(-2, 7), std::exception); }

TEST(MatrixSubTest, HandlesErrorTwoMatrixInput) {
    S21Matrix matrixOne(2, 7);
    S21Matrix matrixTwo(2, 3);
    EXPECT_THROW(matrixOne.sub_matrix(matrixTwo), std::exception);
}

TEST(MatrixMulTest, HandlesZeroMatrixInput) {
    S21Matrix matrixOne;
    S21Matrix matrixTwo(3, 3);
    matrixOne.mul_matrix(matrixTwo);
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesDifferentMatrixInput) {
    S21Matrix matrixOne(3, 3);
    matrixOne.fill_matrix();
    S21Matrix matrixTwo(3, 1);
    matrixTwo(0, 0) = 1.0;
    matrixTwo(1, 0) = 2.0;
    matrixTwo(2, 0) = 3.0;
    matrixOne.mul_matrix(matrixTwo);
    S21Matrix matrixResult(3, 1);
    matrixResult(0, 0) = 8.0;
    matrixResult(1, 0) = 14.0;
    matrixResult(2, 0) = 20.0;
    bool check = matrixOne.eq_matrix(matrixResult);
    EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    S21Matrix matrixThree(3, 3);
    matrixOne.fill_matrix();
    matrixTwo.fill_matrix();
    matrixOne.mul_matrix(matrixTwo);
    matrixThree(0, 0) = 5.0;
    matrixThree(0, 1) = 8.0;
    matrixThree(0, 2) = 11.0;
    matrixThree(1, 0) = 8.0;
    matrixThree(1, 1) = 14.0;
    matrixThree(1, 2) = 20.0;
    matrixThree(2, 0) = 11.0;
    matrixThree(2, 1) = 20.0;
    matrixThree(2, 2) = 29.0;
    bool check = matrixOne.eq_matrix(matrixThree);
    EXPECT_EQ(check, true);
}

TEST(MatrixMulTest, HandlesErrorMatrixInput) {
    S21Matrix matrixOne(2, 7);
    S21Matrix matrixTwo(2, 3);
    EXPECT_THROW(matrixOne.mul_matrix(matrixTwo), std::exception);
}

TEST(MatrixTransposeTest, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne.fill_matrix();
    matrixTwo.fill_matrix();
    matrixOne.transpose();
    bool check = matrixOne.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixCalcComplecsTest, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne(0, 0) = 1.0;
    matrixOne(0, 1) = 2.0;
    matrixOne(0, 2) = 3.0;
    matrixOne(1, 0) = 0.0;
    matrixOne(1, 1) = 4.0;
    matrixOne(1, 2) = 2.0;
    matrixOne(2, 0) = 5.0;
    matrixOne(2, 1) = 2.0;
    matrixOne(2, 2) = 1.0;
    matrixTwo(0, 0) = 0.0;
    matrixTwo(0, 1) = 10.0;
    matrixTwo(0, 2) = -20.0;
    matrixTwo(1, 0) = 4.0;
    matrixTwo(1, 1) = -14.0;
    matrixTwo(1, 2) = 8.0;
    matrixTwo(2, 0) = -8.0;
    matrixTwo(2, 1) = -2.0;
    matrixTwo(2, 2) = 4.0;
    S21Matrix matrixResult = matrixOne.calc_complements();
    bool check = matrixResult.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixCalcComplecsTest, HandlesErrorMatrixInput) {
    S21Matrix matrixOne(2, 7);
    EXPECT_THROW(S21Matrix matrixResult = matrixOne.calc_complements(), std::exception);
}

TEST(MatrixDetermanantTest, HandlesMatrixInput) {
    S21Matrix matrixOne = fill_matrix_example();
    double resultDet = matrixOne.determinant();
    EXPECT_EQ(resultDet, 20);
}

TEST(MatrixDetermanantTest, HandlesMatrixZeroInput) {
    S21Matrix matrixOne(5, 5);
    double resultDet = matrixOne.determinant();
    EXPECT_EQ(resultDet, 0);
}

TEST(MatrixDetermanantTest, HandlesErrorMatrixInput) {
    S21Matrix matrixOne(3, 4);
    EXPECT_THROW(double resultDet = matrixOne.determinant(), std::exception);
}

TEST(MatrixInversetTest, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    matrixOne(0, 0) = 1.0;
    matrixOne(0, 1) = 2.0;
    matrixOne(0, 2) = 3.0;
    matrixOne(1, 0) = 0.0;
    matrixOne(1, 1) = 4.0;
    matrixOne(1, 2) = 2.0;
    matrixOne(2, 0) = 5.0;
    matrixOne(2, 1) = 2.0;
    matrixOne(2, 2) = 1.0;
    matrixTwo(0, 0) = 0.0;
    matrixTwo(0, 1) = -0.1;
    matrixTwo(0, 2) = 0.2;
    matrixTwo(1, 0) = -0.25;
    matrixTwo(1, 1) = 0.35;
    matrixTwo(1, 2) = 0.05;
    matrixTwo(2, 0) = 0.5;
    matrixTwo(2, 1) = -0.2;
    matrixTwo(2, 2) = -0.1;
    S21Matrix matrixResult = matrixOne.inverse_matrix();
    bool check = matrixResult.eq_matrix(matrixTwo);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTestUnary, HandlesMatrixInput) {
    S21Matrix matrixZero(5, 5);
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(matrixOne);
    matrixOne -= matrixTwo;
    bool check = matrixOne.eq_matrix(matrixZero);
    EXPECT_EQ(check, true);
}

TEST(MatrixSubTestBinary, HandlesMatrixInput) {
    S21Matrix matrixZero(5, 5);
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(matrixOne);
    S21Matrix matrixResult = matrixOne - matrixTwo;
    bool check = matrixResult.eq_matrix(matrixZero);
    EXPECT_EQ(check, true);
}

TEST(MatrixSumTestUnary, HandlesMatrixInput) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(matrixOne);
    matrixOne += matrixTwo;
    S21Matrix matrixResult(matrixOne);
    bool check = matrixOne.eq_matrix(matrixResult);
    EXPECT_EQ(check, true);
}

TEST(MatrixSumTestBinary, HandlesMatrixInput) {
    S21Matrix matrixOne = fill_matrix_example();
    S21Matrix matrixTwo(matrixOne);
    S21Matrix matrixResult = matrixOne + matrixTwo;
    matrixOne *= 2;
    bool check = matrixOne.eq_matrix(matrixResult);
    EXPECT_EQ(check, true);
}

TEST(MatrixMulTestBinary, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixTwo(3, 3);
    S21Matrix matrixThree(3, 3);
    matrixOne.fill_matrix();
    matrixTwo.fill_matrix();
    S21Matrix matrixResult = matrixOne * matrixTwo;
    matrixThree(0, 0) = 5.0;
    matrixThree(0, 1) = 8.0;
    matrixThree(0, 2) = 11.0;
    matrixThree(1, 0) = 8.0;
    matrixThree(1, 1) = 14.0;
    matrixThree(1, 2) = 20.0;
    matrixThree(2, 0) = 11.0;
    matrixThree(2, 1) = 20.0;
    matrixThree(2, 2) = 29.0;
    bool check = matrixResult == matrixThree;
    EXPECT_EQ(check, true);
}

TEST(MatrixMulTestUnary, HandlesMatrixInput) {
    S21Matrix matrixOne(3, 3);
    S21Matrix matrixThree(3, 3);
    S21Matrix matrixResult(3, 3);
    matrixOne.fill_matrix();
    matrixResult.fill_matrix();
    matrixResult *= matrixOne;
    matrixThree(0, 0) = 5.0;
    matrixThree(0, 1) = 8.0;
    matrixThree(0, 2) = 11.0;
    matrixThree(1, 0) = 8.0;
    matrixThree(1, 1) = 14.0;
    matrixThree(1, 2) = 20.0;
    matrixThree(2, 0) = 11.0;
    matrixThree(2, 1) = 20.0;
    matrixThree(2, 2) = 29.0;
    bool check = matrixResult == matrixThree;
    EXPECT_EQ(check, true);
}

TEST(NumberMulTestBinary, HandlesMatrixInputRight) {
    S21Matrix matrixOne(3, 3);
    matrixOne.fill_matrix();
    S21Matrix matrixResult = matrixOne * 2.0;
    matrixOne.mul_number(2.0);
    bool check = matrixResult == matrixOne;
    EXPECT_EQ(check, true);
}

TEST(NumberMulTestBinary, HandlesMatrixInputLeft) {
    S21Matrix matrixOne(3, 3);
    matrixOne.fill_matrix();
    S21Matrix matrixResult = 2.0 * matrixOne;
    matrixOne.mul_number(2.0);
    bool check = matrixResult == matrixOne;
    EXPECT_EQ(check, true);
}

TEST(MoveConstruction, HandlesMatrixInputLeft) {
    S21Matrix matrixOne(3, 3);
    matrixOne.fill_matrix();
    S21Matrix matrixResult(std::move(matrixOne));
    ASSERT_EQ(0, matrixOne.getCols());
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

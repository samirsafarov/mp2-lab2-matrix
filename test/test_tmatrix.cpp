#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) /*
можно создать матрицу с положительной длиной*/

{
	ASSERT_NO_THROW(TMatrix<int> m(5)); /*
не утверждать не бросок*/
}

TEST(TMatrix, cant_create_too_large_matrix) /*
не могу создать для большой матрицы*/
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1)); /*утверждать любой бросок*/
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) /*
броски, когда создать матрицу с отрицательной длиной*/
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));     /*утверждать любой бросок*/
}

TEST(TMatrix, can_create_copied_matrix) /*можно создать матрицу Скопировано*/
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m)); /*не утверждать не бросок*/
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) /*скопированы матрицы равен источника одного*/
{
	TMatrix <int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=1;
	TMatrix <int> m2(m1);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1, m2[i][j]); /*ожидать*/
}

TEST(TMatrix, copied_matrix_has_its_own_memory) /*копироваться матрица имеет свою собственную память*/
{
	TMatrix <int> m1(2);
	TMatrix <int> m2(m1);
	EXPECT_NE(&m2,&m1);
}

TEST(TMatrix, can_get_size) /*может получить размер*/
{
	TMatrix <int> m(4);
	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element) /*можно установить и получить элемент*/
{
	TMatrix <int> m(4);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) /*бросает, когда устанавливается элемент с отрицательным индексом*/
{
	TMatrix <int> m(2);
	ASSERT_ANY_THROW(m[-1][0]=1); /*утверждать любой бросок*/	
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) /*бросает, когда устанавливается элемент со слишком большой индекс*/
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[3][0]=1); /*утверждать любой бросок*/
} 

TEST(TMatrix, can_assign_matrix_to_itself) /*может назначить себе матрицу
*/
{
	TMatrix<int> m(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m[i][j]=1;
	m=m;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,m[i][j]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) /*может назначить матриц одинакового размера
*/
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
	m1=m2;
	EXPECT_EQ(1,m1[0][0]);
	EXPECT_EQ(1,m1[0][1]);
	EXPECT_EQ(2,m1[1][0]);
}

TEST(TMatrix, assign_operator_change_matrix_size) /*назначить оператора размер матрицы изменения*/
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(2);
	m1=m2;
	EXPECT_EQ(2,m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size) /*может назначить матриц различного размера*/
{
	TMatrix<int> m1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i;
	m1=m2;
	EXPECT_EQ(0,m1[0][0]);
	EXPECT_EQ(0,m1[0][1]);
	EXPECT_EQ(1,m1[1][0]);
}

TEST(TMatrix, compare_equal_matrices_return_true) /*compare_equal_matrices_return_true*/
{
	TMatrix<int> m1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m2[i][j]=i;
	EXPECT_TRUE(m1==m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true) /*сравнить матрицу с собой вернуться правда*/
{
	TMatrix<int> m1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m1[i][j]=i;
	EXPECT_TRUE(m1==m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) /*матрицы с различным размером не равны
*/
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	EXPECT_TRUE(m1!=m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size) /*можно добавить матриц с одинаковой величины
*/
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
	TMatrix<int> m3(2);
	m3=m1+m2;
	EXPECT_EQ(1,m3[0][0]);
	EXPECT_EQ(1,m3[0][1]);
	EXPECT_EQ(3,m3[1][0]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) /*не могу добавить матриц с размером, не равным*/
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1+m2); /*утверждать любой бросок*/
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) /*можно вычесть матрицы с одинакового размера*/
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
	TMatrix<int> m3(2);
	m3=m2-m1;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,m3[i][j]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) /*косяка вычитать матрицы с размером, не равным*/
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1-m2); /*утверждать любой бросок*/
}

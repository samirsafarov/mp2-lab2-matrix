#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> a(3);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 4;
	TMatrix<int> a1(a);
	EXPECT_EQ(a, a1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> a(2);
	a[1][1] = 1;

	TMatrix<int> a1(a);

	EXPECT_NE(&a, &a1);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> a(10);
  EXPECT_EQ(10, a.GetSize() );

}

TEST(TMatrix, can_set_and_get_element)
{  TMatrix<int> a(10);
a[1][1]=77;
EXPECT_EQ(77, a[1][1]);
  
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{  TMatrix<int> a(10);
ASSERT_ANY_THROW(a[-1][-1]=0);
  
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
 TMatrix<int> a(10);
ASSERT_ANY_THROW(a[MAX_VECTOR_SIZE+1][1] = 0); 
  
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int> a(3);
  a[0][0] = 3;
  a[1][1] = 4;
  a = a;
  EXPECT_EQ(3, a[0][0]);
  EXPECT_EQ(4, a[1][1]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  
	TMatrix<int> a(3), b(3);
	for (int i = 0; i < 3; i++) {
		a[i][i] = i;
	}
	b = a;

	EXPECT_EQ(0, b[0][0]);
	EXPECT_EQ(1, b[1][1]);
	EXPECT_EQ(2, b[2][2]);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
 TMatrix<int> a(3);
	a = TMatrix<int>(4);

	EXPECT_EQ(4, a.GetSize() );
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
 TMatrix<int> a(3), b(2);
	b = a;

	EXPECT_EQ(3, b.GetSize() );
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;

	TMatrix<int> b(2);
	b[0][0] = 1;
	b[0][1] = 2;
	b[1][1] = 3;

	EXPECT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> a(3);
	EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> a(3), b(2);
	EXPECT_FALSE(b == a);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
 
	TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;

	TMatrix<int> b(2);
	b[0][0] = 2;
	b[0][1] = 3;

	TMatrix<int> c(2);
	c[0][0] = 3;
	c[0][1] = 5;

	EXPECT_EQ(c, a+b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
 TMatrix<int> m(2);

	TMatrix<int> m1(3);

	ASSERT_ANY_THROW(m1+m);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
 TMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;

	TMatrix<int> b(2);
	b[0][0] = 2;
	b[0][1] = 3;

	TMatrix<int> c(2);
	c[0][0] = -1;
	c[0][1] = -1;

	EXPECT_EQ(c, a-b);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> a(2);

	TMatrix<int> b(3);

	ASSERT_ANY_THROW(b-a);
}

/*TEST(TMatrix, umnozhenie)
{
  TMatrix<int> a(2);
   TMatrix<int> b(2);
    TMatrix<int> c(2);
   a[0][0]= 2;
   a[0][1]= 3;
   a[1][1]= 1;
   
   b[0][0]= 1;
   b[0][1]= 0;
   b[1][1]= 3;

   c=a*b;
	EXPECT_EQ(2, c[0][0]);
	EXPECT_EQ(9, c[0][1]);
}
*/
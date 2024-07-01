# ifndef MATRIX_HPP
# define MATRIX_HPP
# include <vector>  
  void start ();
  std::string choose_matrix_operation(); 
  std::vector <std::vector<double> > number_of_the_lines_and_columns_of_the_matrix ( int );
  std::vector<std::vector<double>> vec_2D_matrixs_lines_members( int , int , std::vector<double> );
  std::vector<std::vector<double>> vec_2D_matrix_columns_members ( int , int , std::vector<double> );
  std::vector<std::vector<double>> matrixs_input_wise ( std::vector<std::vector<double>> , int );
  std::vector<double> matrix_answer ();
  std::vector<std::vector<double>> mulitply_two_matrix ( std::vector<std::vector<double>> , std::vector<std::vector<double>> , std::vector<std::vector<double>> , std::vector<std::vector<double>> , std::vector<std::vector<double>> , std::vector<std::vector<double>> );
  std::vector<std::vector<double>> sum_and_sub_two_matrix ( std::vector<std::vector<double>> , std::vector<double> , std::vector<double> , int );
  std::string& quit_or_continue( std::vector<std::vector<double>> , int , int );
# endif

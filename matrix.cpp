# include <iostream>
# include <random>
# include <chrono>
# include <vector>
# include <bitset>
# include <unordered_map>
# include "matrix.hpp"
# include "const_lines_and_columns.cpp"
# define next_line std::cout << '\n';



int main () {
  //start(); 
   

  std::vector<std::vector<double>> new_matrix { matrix_answer() };
  
  # if 0

    3	  5	100
   670	300	140
   200	500	300


  212 2121  2121 
212  212  211 2
2121  21  211

  std::vector< std::vector<double> > l_and_c { number_of_the_lines_and_columns_of_the_matrix() };
  std::vector < std::vector<double> > matrixs_wise { matrix( l_and_c ) };
  std::vector<double> matrixs_1_wise {};
  std::vector<double> matrixs_2_wise {};


  for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c [ 0 ][ 1 ] ; ++ counter ) {
    matrixs_1_wise.push_back( matrixs_wise [ 0 ][ counter ] );

  }


  for ( int counter { 0 }; counter < l_and_c[ 1 ][ 0 ] * l_and_c [ 1 ][ 1 ]; ++ counter ) {
    matrixs_2_wise.push_back( matrixs_wise [ 1 ][ counter ] );

  }
  
  /* l_and_c[ 0 ][ 0 ] == number_of_the_matrixs_1_lines 
     l_and_c[ 0 ][ 1 ] == number_of_the_matrixs_1_columns
     l_and_c[ 1 ][ 0 ] == number_of_the_matrixs_2_lines 
     l_and_c[ 1 ][ 1 ] == number_of_the_matrixs_2_columns 
  */

  std::vector<std::vector<double>> line_member_matrix_1 { vec_2D_matrixs_lines_members( l_and_c[ 0 ][ 0 ] , l_and_c[ 0 ][ 1 ] , matrixs_1_wise ) }; 
  std::vector<std::vector<double>> line_member_matrix_2 { vec_2D_matrixs_lines_members( l_and_c[ 1 ][ 0 ] , l_and_c[ 1 ][ 1 ] , matrixs_2_wise ) }; 
  std::vector<std::vector<double>> column_member_martix_1 { vec_2D_matrix_columns_members( l_and_c[ 0 ][ 0 ] , l_and_c[ 0 ][ 1 ] , matrixs_1_wise ) };  
  std::vector<std::vector<double>> column_member_martix_2 { vec_2D_matrix_columns_members( l_and_c[ 1 ][ 0 ] , l_and_c[ 1 ][ 1 ] , matrixs_2_wise ) };  

  mulitply_two_matrix( l_and_c , matrixs_wise , line_member_matrix_1 , line_member_matrix_2 , column_member_martix_1 , column_member_martix_2 );

  # endif
  
return 0; 
}

void start() {
  next_line
  std::cout << "Press any key to start the progeram : " << '\n';
  std::string start_botton {};
  std::getline( std::cin >> std::ws , start_botton );
  
}

std::string choose_matrix_operation() {
  std::string input {};

  while ( input != "plus" && input != "mines" && input != "mulitiply" && input != "det" &&input != "inverse" ) {
    next_line
    next_line
    std::cout << "Enter plus : To Sum two matrix " << '\n';
    next_line
    std::cout << "Enter mines : To subtrac to matrix " << '\n';
    next_line
    std::cout << "Enter mulitiply : To mulitiply two matrix " << '\n';
    next_line
    std::cout << "Enter det : To calculate the detrmine of a matrix " << '\n';
    next_line
    std::cout << "Enter inverse : To calculate inverse of a matrix " << '\n';
    std::getline( std::cin >> std::ws , input );

    if ( input != "plus" && input != "mines" && input != "mulitiply" && input != "det" && input != "inverse" ) {
      next_line
      next_line
      std::cout << "Wrong input " << '\n';
      std::cout << "Please enter again " << '\n';
    } 
    
  }

return input;
}

std::string quit_or_continue( std::vector<std::vector<double>> the_new_matrix , int the_new_matrixs_lines , int the_new_matrixs_columns , int matrixs_determination , int str_to_int_for_matrixs_operations ) {
  std::string quit_or_continue {};
  next_line
  
  if ( str_to_int_for_matrixs_operations == 1 || str_to_int_for_matrixs_operations == 2 || str_to_int_for_matrixs_operations == 3 ) {
    std::cout << "The new matrix is : " << '\n';

    for ( int counter { 0 }; counter < the_new_matrixs_lines; ++ counter ) {
      
      for ( int nested_counter { 0 }; nested_counter < the_new_matrixs_columns; ++ nested_counter ) {
        std::cout << the_new_matrix[ counter ][ nested_counter ] << '\t';

      }

      std::cout << '\n';


    }
  }

  else {
    std::cout << "The matrixs det is : " << matrixs_determination << '\n';
  }

  next_line
  while ( quit_or_continue != "quit" && quit_or_continue != "continue" ) {
    next_line
    std::cout << "Enter continue : To do other matrix operation with the new matrix" << '\n';
    std::cout << "Enter quit : To skip the first part of the bulid " << '\n';
    std::getline ( std::cin >> std::ws , quit_or_continue );
  
  }

return quit_or_continue;
}





auto str_to_int ( std::string input ) {
  std::unordered_map< std::string , int > string_to_intgers_types {
    { "plus" , 1 } , { "mines" , 2 } , { "mulitiply" , 3 } , { "det" , 4 } , { "inverse" , 5 }

  };

  auto it { string_to_intgers_types.find( input ) };

  if ( it != string_to_intgers_types.end() ) {
    return it->second;
  }

return -1;
}

std::string int_to_str ( int input ) {
  std::unordered_map < int , std::string > int_to_str_changer {
    { 1 ,  "sum " } , { 2 , "subtrack " } , { 4 ,  "determination " } , { 5 , "inverse " }
 
  };

  auto it { int_to_str_changer.find( input ) };
 
   if ( it != int_to_str_changer.end() ) {
     return it->second;

   }
  
return "null";
}




std::vector<std::vector<double>> matrix_answer() {
  std::vector<std::vector<double>> matrix_output_for_bit_manipluation {};

  while ( true ) {
    std::vector< std::vector<double> > l_and_c {};
    std::vector < std::vector<double> > matrixs_wise {};
    std::vector<std::vector<double>> m1 {};
    std::vector<double> matrixs_1_wise {};
    std::vector<double> matrixs_2_wise {};
    std::vector<std::vector<double>> line_member_matrix_1 {}; 
    std::vector<std::vector<double>> line_member_matrix_2 {}; 
    std::vector<std::vector<double>> column_member_martix_1 {};  
    std::vector<std::vector<double>> column_member_martix_2 {};  
    std::vector<std::vector<double>> new_matrixs_lines_and_columns {};
    double det {};
    next_line
    next_line 
    std::string q_or_c {}; 
    std::string matrixs_opearation_that_user_want { choose_matrix_operation() };
    int string_to_intger_changer { str_to_int ( matrixs_opearation_that_user_want ) };  
    static std::vector<std::vector<double>> the_new_matrix ( ( ( string_to_intger_changer == 4 || string_to_intger_changer == 5 )? 1 : 2 ) );

    std::cout << string_to_intger_changer << '\n';

    switch ( string_to_intger_changer ) {
      case 1:
        next_line
        std::cout << "You entered plus " << '\n';
        l_and_c = number_of_the_lines_and_columns_of_the_matrix( string_to_intger_changer );
        matrixs_wise = matrixs_input_wise( l_and_c , string_to_intger_changer );
       

        for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c[ 0 ][ 1 ]; ++ counter ) {
          matrixs_1_wise.push_back( matrixs_wise[ 0 ][ counter ] );

        }

        for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c[ 0 ][ 1 ]; ++ counter ) {
          matrixs_2_wise.push_back( matrixs_wise[ 1 ][ counter ] );

        }

        the_new_matrix = sum_and_sub_two_matrix ( l_and_c , matrixs_1_wise , matrixs_2_wise , string_to_intger_changer );
        break;

      case 2:
        next_line
        std::cout << "You entered mines " << '\n'; 
        l_and_c = number_of_the_lines_and_columns_of_the_matrix( string_to_intger_changer );
        matrixs_wise = matrixs_input_wise ( l_and_c , string_to_intger_changer );
        
        for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c [ 0 ][ 1 ] ; ++ counter ) {
          matrixs_1_wise.push_back( matrixs_wise [ 0 ][ counter ] );

        }


        for ( int counter { 0 }; counter < l_and_c[ 1 ][ 0 ] * l_and_c [ 1 ][ 1 ]; ++ counter ) {
          matrixs_2_wise.push_back( matrixs_wise [ 1 ][ counter ] );

        }

        the_new_matrix = sum_and_sub_two_matrix ( l_and_c , matrixs_1_wise , matrixs_2_wise , string_to_intger_changer );
        break;

      case 3:
        next_line
        std::cout << "You entered mulitiply " << '\n';
        next_line
        l_and_c = number_of_the_lines_and_columns_of_the_matrix( string_to_intger_changer );
        matrixs_wise = matrixs_input_wise ( l_and_c , string_to_intger_changer );
        
        for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c [ 0 ][ 1 ] ; ++ counter ) {
          matrixs_1_wise.push_back( matrixs_wise [ 0 ][ counter ] );

        }


        for ( int counter { 0 }; counter < l_and_c[ 1 ][ 0 ] * l_and_c [ 1 ][ 1 ]; ++ counter ) {
          matrixs_2_wise.push_back( matrixs_wise [ 1 ][ counter ] );

        }

        line_member_matrix_1 = vec_2D_matrixs_lines_members( l_and_c[ 0 ][ 0 ] , l_and_c[ 0 ][ 1 ] , matrixs_1_wise );  
        line_member_matrix_2 = vec_2D_matrixs_lines_members( l_and_c[ 1 ][ 0 ] , l_and_c[ 1 ][ 1 ] , matrixs_2_wise );
        column_member_martix_1 = vec_2D_matrix_columns_members( l_and_c[ 0 ][ 0 ] , l_and_c[ 0 ][ 1 ] , matrixs_1_wise );        
        column_member_martix_2 = vec_2D_matrix_columns_members( l_and_c[ 1 ][ 0 ] , l_and_c[ 1 ][ 1 ] , matrixs_2_wise ); 
        the_new_matrix = mulitply_two_matrix(  l_and_c , matrixs_wise , line_member_matrix_1 , line_member_matrix_2 , column_member_martix_1 , column_member_martix_2 );
        break;

      case 4:
        next_line
        std::cout << "You entered det " << '\n';
        l_and_c = number_of_the_lines_and_columns_of_the_matrix( string_to_intger_changer );
        matrixs_wise = matrixs_input_wise( l_and_c , string_to_intger_changer );

        for ( int counter { 0 }; counter < l_and_c.size(); ++ counter ) {
          the_new_matrix[ counter ].resize( l_and_c[ 0 ][ 1 ] );

        }


        for ( int counter { 0 }; counter < l_and_c[ 0 ][ 0 ] * l_and_c[ 0 ][ 1 ]; ++ counter ) {
          matrixs_1_wise.push_back( matrixs_wise[ 0 ][ counter ] );

        }

        det = matrix_determination( l_and_c , matrixs_1_wise );
        break;

      case 5:
        next_line
        std::cout << "You entered inverse " << '\n';
        l_and_c = number_of_the_lines_and_columns_of_the_matrix( string_to_intger_changer );
        matrixs_wise = matrixs_input_wise( l_and_c , string_to_intger_changer );
        break;

    }

    
    q_or_c = quit_or_continue( the_new_matrix , the_new_matrix.size() , the_new_matrix[ 0 ].size() , det , string_to_intger_changer );

    if ( q_or_c == "quit" ) {
      matrix_output_for_bit_manipluation = the_new_matrix;
      break;
    }
    

  }

  
return matrix_output_for_bit_manipluation;
}



std::vector <std::vector<double> > number_of_the_lines_and_columns_of_the_matrix( int str_to_int_from_the_matrix_operation  ) {
  std::vector < std::vector<double> > lines_and_columns ( ( ( str_to_int_from_the_matrix_operation == 4 || str_to_int_from_the_matrix_operation == 5 )? 1 : 2 ) );
  std::string int_to_string { int_to_str( str_to_int_from_the_matrix_operation ) };

  std::cout << "size : " << lines_and_columns.size() << '\n';

  if ( str_to_int_from_the_matrix_operation == 3 ) {
    for ( int counter { 1 }; counter <= lines_and_columns.size(); ++ counter ) {
      for ( int nested_counter { 0 }; nested_counter < lines_and_columns.size(); ++ nested_counter ) {
        double final_input {};
       
        while ( true ) {
          next_line
          std::cout << "Enter the number of the " << counter << "_matrixs " << ( ( nested_counter == 0 )? "lines : " : "columns : " ) << '\n';
          double input {};
          std::cin >> input;

          final_input = input; 

          if ( final_input < 0 || final_input - static_cast<int> ( final_input ) != 0 ) {
            next_line
            std::cout << "Wrong input " << '\n';
            std::cout << "Please enter again " << '\n'; 
          }
          
          else { 
            break;
          }

        }
        
        lines_and_columns[ counter - 1 ].push_back( final_input );
        
      }
    }
  
  }

  else if ( str_to_int_from_the_matrix_operation == 1 || str_to_int_from_the_matrix_operation == 2 ) {
    std::vector<double> inputs {};

    for ( int counter { 0 }; counter < 2; ++ counter ) {
      std::cout << "Enter the " << ( ( counter == 0 )? "lines " : "columns " ) << "of both matrix to " << int_to_string << " : " << '\n';
      double input {};
      std::cin >> input;
      inputs.push_back( input );

    }

    for ( int counter { 0 }; counter < lines_and_columns.size(); ++ counter ) {
      
      for ( int nested_counter { 0 }; nested_counter < 2; ++ nested_counter ) {
        lines_and_columns[ counter ].push_back( (( nested_counter % 2 == 0 )? inputs[ 0 ] : inputs[ 1 ] ) );
      }

    }

  }


  else {

    for ( int counter { 0 }; counter < lines_and_columns.size(); ++ counter ) {
      lines_and_columns[ counter ].resize( 2 ); 

    }


    double inputs_for_error {}; 

    while ( true ) {      
      next_line
      std::cout << "Enter the lines and columns of the square of the the matrix : " << '\n';  
      double square_matrixs_lines_and_columns {};
      std::cin >> square_matrixs_lines_and_columns;
      inputs_for_error = square_matrixs_lines_and_columns;

      if ( std::cin.fail() || inputs_for_error <= 0 || inputs_for_error - static_cast<int> (inputs_for_error ) != 0 ) {
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
        next_line
        std::cout << "Wrong input " << '\n';
        std::cout << "Please enter again " << '\n';
      }

      else{ 
        break;
      }

    }

    std::fill( lines_and_columns[ 0 ].begin() , lines_and_columns[ 0 ].end() , inputs_for_error );

  }

  next_line

  for ( int counter { 0 }; counter < lines_and_columns.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < 2; ++ nested_counter ) {
      std::cout << lines_and_columns[ counter ][ nested_counter ] << '\t';

    }

    std::cout << '\n';

  }

return lines_and_columns;
}

std::vector < std::vector<double> > matrixs_input_wise ( std::vector < std::vector<double> > number_of_the_lines_and_columns , int str_to_int_from_the_matrix_operation  ) {
  std::vector < std::vector<double> > matrixs_wise ( ( ( str_to_int_from_the_matrix_operation == 4 || str_to_int_from_the_matrix_operation == 5 )? 1 : 2 ) );
  std::cout << "size : " << matrixs_wise.size() << '\n';
  
  int No_lines { 1 };
  int No_columns { 0 }; 

  for ( int counter { 0 }; counter < matrixs_wise.size(); ++ counter ) {
    next_line
    double input_for_error {};

    for ( int nested_counter { 0 }; nested_counter < number_of_the_lines_and_columns[ 0 ][ 0 ] * number_of_the_lines_and_columns[ 0 ][ 1 ]; ++ nested_counter ) {
      ++ No_columns;
      while ( true ) {
        next_line
        std::cout << "Enter wise " << ( ( counter == 0 )? " A " : " B " ) << No_lines << No_columns << " for " << counter + 1 <<"_matrix " << " : " << '\n';
        double wise {};
        std::cin >> wise;

        if (std::cin.fail() ) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            next_line
            std::cout << "Wrong input. Please enter a valid integer." << '\n';
        }

        if ( wise - static_cast<int> ( wise ) != 0 ) {
          next_line
          std::cout << "Wrong input " << '\n';
          std::cout << "Please enter again " << '\n';

        }

        else { 
          input_for_error = wise;
          break;
        }

      }

      if ( No_columns ==  number_of_the_lines_and_columns[ counter ][ 1 ] ) {
        ++No_lines;
        No_columns = 0;
      }
      
      matrixs_wise[ counter ].push_back( input_for_error ); 

    }

    No_lines = 1;
    No_columns = 0;


  }

return matrixs_wise;
}



std::vector< std::vector<double> > vec_2D_matrixs_lines_members ( int number_of_the_matrix_lines , int number_of_the_matrix_columns , std::vector<double> matrixs_wise ) {
  std::vector<std::vector<double>> line_member_matrix ( number_of_the_matrix_lines );
  int counter_for_matrix_lines { 0 };

  for ( int counter { 0 }; counter < line_member_matrix.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrix_columns; ++ nested_counter ) {
      line_member_matrix[ counter ].push_back( matrixs_wise[ counter_for_matrix_lines ] );
      ++ counter_for_matrix_lines;
    } 

  }

return line_member_matrix;
}


std::vector<std::vector<double>> vec_2D_matrix_columns_members ( int number_of_the_matrix_lines , int number_of_the_matrix_columns , std::vector<double> matrixs_wise ) {
  std::vector<std::vector<double>> column_member_of_matrix ( number_of_the_matrix_columns );
  int counter_for_matrix_columns {};

  for ( int counter { 0 }; counter < column_member_of_matrix.size(); ++ counter ) {
    counter_for_matrix_columns = counter;
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrix_lines; ++ nested_counter ) {
      column_member_of_matrix[ counter ].push_back( matrixs_wise[ counter_for_matrix_columns ] );
      counter_for_matrix_columns += number_of_the_matrix_columns;
    }

  }

return column_member_of_matrix;
}


std::vector<double> multiplication_operation_of_the_matrix1_by_matrix_2( std::vector<std::vector<double>> matrixs_1_line_members , std::vector<std::vector<double>> matrixs_2_column_members ,  int number_of_the_matrix_1_lines , int  number_of_the_matrix_1_columns , int number_of_the_matrixs_2_lines , int number_of_the_matrixs_2_columns ) { 
  std::vector<double> vec_matrixs_2_columns {};

  for ( int counter { 0 }; counter < matrixs_2_column_members.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrixs_2_lines; ++ nested_counter ) {
      vec_matrixs_2_columns.push_back( matrixs_2_column_members[ counter ][ nested_counter ] );

    }
  }
  
  std::vector<double> vec_answer_of_multiplication_operation_of_the_matrix_1_by_matrix_2 {};
  int counter_for_matrix_1_lines { 0 };


  for ( int counter { 0 }; counter < matrixs_1_line_members.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrixs_2_lines * number_of_the_matrixs_2_columns; ++ nested_counter ) {
      vec_answer_of_multiplication_operation_of_the_matrix_1_by_matrix_2.push_back( matrixs_1_line_members[ counter ][ counter_for_matrix_1_lines ] * vec_matrixs_2_columns[ nested_counter ]);
      ++ counter_for_matrix_1_lines;

      if ( counter_for_matrix_1_lines == number_of_the_matrix_1_columns ) {
        counter_for_matrix_1_lines = 0; 
      }


    }


  } 

  
return vec_answer_of_multiplication_operation_of_the_matrix_1_by_matrix_2;
}

std::vector<double> multiplication_operation_of_the_matrix_2_by_matrix_1 ( std::vector<std::vector<double>> matrixs_1_column_members , std::vector<std::vector<double>> matrixs_2_lines_members ,  int number_of_the_matrix_1_lines , int  number_of_the_matrix_1_columns , int number_of_the_matrixs_2_lines , int number_of_the_matrixs_2_columns ) {
  std::vector<double> vec_matrixs_1_columns {};
  std::vector<double> vec_answer_of_multiplication_operation_of_the_matrix_2_by_matrix_1 {};

  for ( int counter { 0 }; counter < matrixs_1_column_members.size() ; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrix_1_lines; ++ nested_counter ) {
      vec_matrixs_1_columns.push_back( matrixs_1_column_members[ counter ][ nested_counter ]);

    }

  }



  int counter_for_matrix_2_lines { 0 };

  for ( int counter { 0 }; counter < matrixs_2_lines_members.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrix_1_lines * number_of_the_matrix_1_columns; ++ nested_counter ) {
      vec_answer_of_multiplication_operation_of_the_matrix_2_by_matrix_1.push_back( matrixs_2_lines_members[ counter ][ counter_for_matrix_2_lines ] * vec_matrixs_1_columns[ nested_counter ] );
      ++ counter_for_matrix_2_lines;

      if ( counter_for_matrix_2_lines == number_of_the_matrixs_2_columns ) {
        counter_for_matrix_2_lines = 0;
      }
    }

  }

  next_line

return vec_answer_of_multiplication_operation_of_the_matrix_2_by_matrix_1;
}

std::vector<std::vector<double>> classified_multiplication_values_of_new_matrix ( std::vector<double> matrixs_multiplication_values , int number_of_the_matrix_1_lines , int number_of_the_matrix_1_columns , int number_of_the_matrix_2_lines , int number_of_the_matrix_2_columns ) {
  std::vector<std::vector<double>> classified_matrixs_multiplication_values_based_on_thier_lines_and_columns ( number_of_the_matrix_1_lines * number_of_the_matrix_2_columns );
  int counter_for_multiplication_values { 0 };

  for ( int counter { 0 }; counter < classified_matrixs_multiplication_values_based_on_thier_lines_and_columns.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < number_of_the_matrix_2_lines; ++ nested_counter ) {
      classified_matrixs_multiplication_values_based_on_thier_lines_and_columns[ counter ].push_back( matrixs_multiplication_values[ counter_for_multiplication_values ] );
      ++ counter_for_multiplication_values;
    }

  }



return classified_matrixs_multiplication_values_based_on_thier_lines_and_columns; 
}


std::vector<std::vector<double>> the_new_matrix( std::vector<std::vector<double>> classified_multiplication_values , int new_matrixs_lines , int new_matrixs_columns ) {
  std::vector<double> rowSums( classified_multiplication_values.size(), 0);
  
  for ( int counter { 0 }; counter < classified_multiplication_values.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < classified_multiplication_values[ counter ].size(); ++ nested_counter ) {
      rowSums[ counter ] += classified_multiplication_values[ counter ][ nested_counter ];
    } 

  }
  
  next_line
  next_line

  std::cout << "The new matrix in " << new_matrixs_lines << " * " << new_matrixs_columns << '\n';

  int counter_for_the_new_matrix_wise { 0 };

  for ( int counter { 0 }; counter < new_matrixs_lines; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < new_matrixs_columns; ++ nested_counter ) {
      std::cout << rowSums[ counter_for_the_new_matrix_wise ] << '\t';
      ++ counter_for_the_new_matrix_wise;
    }

    std::cout << '\n';

  }

  std::vector<std::vector<double>> change_the_vector_in_vec_2D ( new_matrixs_lines );
  
  counter_for_the_new_matrix_wise = 0;

  for ( int counter { 0 }; counter < change_the_vector_in_vec_2D.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < new_matrixs_columns; ++ nested_counter ) {
      change_the_vector_in_vec_2D[ counter ].push_back( rowSums[ counter_for_the_new_matrix_wise ] );
      ++ counter_for_the_new_matrix_wise;
    }


  }


return change_the_vector_in_vec_2D;
}


std::vector<std::vector<double>> sum_and_sub_two_matrix ( std::vector<std::vector<double>> new_matrixs_lines_and_columns , std::vector<double> matrix_1_wise , std::vector<double> matrix_2_wise , int str_to_int_for_matrixs_operation  ) {
  next_line
  std::vector<std::vector<double>> final_matrix ( new_matrixs_lines_and_columns[ 0 ][ 0 ] );
  std::cout << "The matrixs_1 " <<  " ( " << new_matrixs_lines_and_columns[ 0 ][ 0 ] << " * " << new_matrixs_lines_and_columns[ 0 ][ 1 ] << " ) " << " wise is : " << '\n';
  int counter_for_matrixs_wise { 0 }; 

  for ( int counter { 0 }; counter < new_matrixs_lines_and_columns[ 0 ][ 0 ]; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < new_matrixs_lines_and_columns[ 0 ][ 1 ]; ++ nested_counter ) {
      std::cout << matrix_1_wise[ counter_for_matrixs_wise ] << '\t';
      ++ counter_for_matrixs_wise;
    }

    std::cout << '\n';

  }

  counter_for_matrixs_wise = 0;

  next_line
  std::cout << "The matrixs_2 " <<  " ( " << new_matrixs_lines_and_columns[ 1 ][ 0 ] << " * " << new_matrixs_lines_and_columns[ 1 ][ 1 ] << " ) " << " wise is : " << '\n';

  for ( int counter { 0 }; counter < new_matrixs_lines_and_columns[ 1 ][ 0 ]; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < new_matrixs_lines_and_columns[ 1 ][ 1 ]; ++ nested_counter ) {
      std::cout << matrix_2_wise[ counter_for_matrixs_wise ] << '\t';
      ++ counter_for_matrixs_wise;

    }

    std::cout << '\n';

  }

  counter_for_matrixs_wise = 0;

  if ( str_to_int_for_matrixs_operation == 1 ) {
    
    for ( int counter { 0 }; counter < new_matrixs_lines_and_columns[ 0 ][ 0 ]; ++ counter ) {
      
      for ( int nested_counter { 0 }; nested_counter < new_matrixs_lines_and_columns[ 0 ][ 1 ]; ++ nested_counter ) {
        final_matrix[ counter ].push_back( matrix_1_wise[ counter_for_matrixs_wise ] + matrix_2_wise[ counter_for_matrixs_wise ] );
        ++ counter_for_matrixs_wise;
      }

    }


  }

  counter_for_matrixs_wise = 0;


  if ( str_to_int_for_matrixs_operation == 2 ) {

    for ( int counter { 0 }; counter < new_matrixs_lines_and_columns[ 1 ][ 0 ]; ++ counter ) {
      
      for ( int nested_counter { 0 }; nested_counter < new_matrixs_lines_and_columns[ 1 ][ 1 ]; ++ nested_counter ) {
        final_matrix[ counter ].push_back( matrix_1_wise[ counter_for_matrixs_wise ] - matrix_2_wise[ counter_for_matrixs_wise ] );
        ++ counter_for_matrixs_wise;
      }

    }


  }


return final_matrix;
}


std::vector<std::vector<double>> mulitply_two_matrix ( std::vector< std::vector<double> > lines_and_columns , std::vector<std::vector<double>> two_matrix , std::vector<std::vector<double>> l_m_m_1 , std::vector<std::vector<double>> l_m_m_2 , std::vector<std::vector<double>> c_m_m_1 , std::vector<std::vector<double>> c_m_m_2 ) {
  std::vector<double> new_matrixs_lines_and_columns_number_by_matrix_1_multiply_matrix_2 {};
  std::vector<double> new_matrixs_lines_and_columns_number_by_matrix_2_multiply_matrix_1 {};
  std::vector<std::vector<double>> new_matrix_by_mulitiply_matrix_1_to_matrix_2 {};
  std::vector<std::vector<double>> new_matrix_by_mulitiply_matrix_2_to_matrix_1 {};
  
  if ( lines_and_columns[ 0 ][ 1 ] == lines_and_columns[ 1 ][ 0 ] ) {
    std::cout << "The matrix_1 is multiplyable by matrix_2 " << '\n';
    std::cout << "The new matrix will be in ( " << lines_and_columns[ 0 ][ 0 ] << "*" << lines_and_columns[ 1 ][ 1 ] << " ) " << '\n';
    new_matrixs_lines_and_columns_number_by_matrix_1_multiply_matrix_2 = { lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 1 ][ 1 ] };
    std::vector<double> m_values { multiplication_operation_of_the_matrix1_by_matrix_2( l_m_m_1 , c_m_m_2 , lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 0 ][ 1 ] , lines_and_columns[ 1 ][ 0 ] , lines_and_columns[ 1 ][ 1 ] ) };
    next_line
    std::vector<std::vector<double>> C_M_V_O_N_M { classified_multiplication_values_of_new_matrix ( m_values , lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 0 ][ 1 ] , lines_and_columns[ 1 ][ 0 ] , lines_and_columns[ 1 ][ 1 ] ) };
    new_matrix_by_mulitiply_matrix_1_to_matrix_2 = the_new_matrix( C_M_V_O_N_M , lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 1 ][ 1 ] );

  }

  next_line
  next_line
  next_line
  next_line

  if ( lines_and_columns[ 1 ][ 1 ] == lines_and_columns[ 0 ][ 0 ] ) {
    std::cout << "The matrix_2 is multiplyable by matrix_1 " << '\n';
    std::cout << "The new matrix will be in ( " << lines_and_columns[ 1 ][ 0 ] << "*" << lines_and_columns[ 0 ][ 1 ] << " ) " << '\n';
    new_matrixs_lines_and_columns_number_by_matrix_2_multiply_matrix_1 = { lines_and_columns[ 1 ][ 0 ] , lines_and_columns[ 0 ][ 1 ] };
    std::vector<double> m_values { multiplication_operation_of_the_matrix_2_by_matrix_1( c_m_m_1 , l_m_m_2 , lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 0 ][ 1 ] , lines_and_columns[ 1 ][ 0 ] , lines_and_columns[ 1 ][ 1 ] ) };
    std::vector<std::vector<double>> C_M_V_O_N_M { classified_multiplication_values_of_new_matrix ( m_values , lines_and_columns[ 1 ][ 0 ] , lines_and_columns [ 1 ][ 1 ] , lines_and_columns[ 0 ][ 0 ] , lines_and_columns[ 0 ][ 1 ]) };
    new_matrix_by_mulitiply_matrix_2_to_matrix_1 = the_new_matrix( C_M_V_O_N_M , lines_and_columns[ 1 ][ 0 ] , lines_and_columns[ 0 ][ 1 ] );
  }
  

  if ( lines_and_columns[ 0 ][ 1 ] != lines_and_columns[ 1 ][ 0 ] && lines_and_columns[ 1 ][ 1 ] != lines_and_columns[ 0 ][ 0 ] ) {
    std::cout << "The matrix_1 and matrix_2 is not multiplyable " << '\n';
    return { { 0 , 0 } , { 0 , 0 } };
  }
  
  next_line
  next_line
  std::string input {};
  if ( lines_and_columns[ 0 ][ 1 ] == lines_and_columns[ 1 ][ 0 ] && lines_and_columns[ 1 ][ 1 ] == lines_and_columns[ 0 ][ 0 ] ) {
    std::string final_input {};

    while ( true ) {
      next_line
      std::cout << "Enter m1 to m2 : To choose final input from the new matrix by mulituplying matrix_1 to matrix_2 " << '\n';
      std::cout << "Enter m2 to m1 : To choose final input from the new matrix by mulituplying matrix_2 to matrix_1 " << '\n';
      std::string m1_to_m2_or_m2_to_m1 {};
      std::getline( std::cin >> std::ws , m1_to_m2_or_m2_to_m1 );
      final_input = m1_to_m2_or_m2_to_m1;

      if ( final_input != "m1 to m2" && final_input != "m2 to m1" ) {
        next_line
        std::cout << "Wrong input " << '\n';
        std::cout << "Please enter again " << '\n';
      }

      else {
        break;
      }
    
    }

    if ( final_input == "m1 to m2" ) {
      return new_matrix_by_mulitiply_matrix_1_to_matrix_2;
    }

    else if ( final_input == "m2 to m1" ) { 
      return new_matrix_by_mulitiply_matrix_2_to_matrix_1;
    }
  }
  

  else {
    
    if ( lines_and_columns[ 0 ][ 1 ] == lines_and_columns[ 1 ][ 0 ] ) {
      return new_matrix_by_mulitiply_matrix_1_to_matrix_2;
    }

    else if ( lines_and_columns[ 1 ][ 1 ] == lines_and_columns[ 0 ][ 0 ] ) {
      return new_matrix_by_mulitiply_matrix_2_to_matrix_1;
    }


  }




return { { 0 , 0 } , { 0 , 0 } };
}

/*
 1 2
 3 4 

 1 == 0 , 2 == 1 , 3 == 2 , 4 == 3 

 ( 1*4 ) - ( 2 * 3 ) == -2



*/

double detarmination_for_2_by_2_matrix ( std::vector<double> matrix_wise ) {
  double det { ( matrix_wise[ 0 ] * matrix_wise [ 3 ] ) - ( matrix_wise[ 1 ] * matrix_wise[ 2 ] ) };
return det;
}

std::vector<std::vector<double>> vec_main_diameter_of_double_matrix ( std::vector<double> matrix_wise ) {
  std::vector<std::vector<double>> main_diameter_wises ( 3 );
  int num { 0 };

  for ( int counter { 0 }; counter < 1; ++ counter ) {
    
    for ( int nested_counte { 0 }; nested_counte < 3 ; ++ nested_counte ) {
      main_diameter_wises[ 0 ].push_back( matrix_wise[ 4 * nested_counte ] );

    }

    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      main_diameter_wises[ 1 ].push_back( matrix_wise[ num + 1 ] );
      
      num = (( nested_counter == 1 )? 4 : 14 );

    }
    
    num = 2;

    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      main_diameter_wises[ 2 ].push_back( matrix_wise[ num ] );
      
      num = ( ( nested_counter == 1 )? 12 : 16 );

    }



  }

  next_line


  for ( int counter { 0 }; counter < main_diameter_wises.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      std::cout << main_diameter_wises[ counter ][ nested_counter ] << '\t';

    }

    std::cout << '\n';


  }

return main_diameter_wises;
}


std::vector<std::vector<double>> vec_side_diameter_of_double_matrix( std::vector<double> matrixs_wise ) {
  std::vector<std::vector<double>> side_diameter_wises ( 3 );
  int num { 11 };

  for ( int counter { 0 }; counter < side_diameter_wises.size(); ++ counter ) {

    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      side_diameter_wises[ counter ].push_back( matrixs_wise[ num ] );
      num += 2;

    }

    num = ( ( counter == 1 )?  8 : 5 );


  }

  next_line

  for ( int counter { 0 }; counter < 3; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      std::cout << side_diameter_wises[ counter ][ nested_counter ] << '\t';

    }

    std::cout << '\n';


  }

return side_diameter_wises;
}


double matrixs_detarmination_in_rule_of_sarrus ( std::vector<double> matrixs_wise_that_user_entered , std::vector<std::vector<double>> lines_and_columns_of_the_matrix ) {
  std::vector<double> double_matrix {};  
  int counter_for_matrixs_wise {};
  next_line

  for ( int counter { 0 }; counter < lines_and_columns_of_the_matrix[ 0 ][ 0 ] * lines_and_columns_of_the_matrix[ 0 ][ 1 ] * 2; ++ counter ) {
    double_matrix.push_back( matrixs_wise_that_user_entered[ counter_for_matrixs_wise ] );
    ++counter_for_matrixs_wise;

    if ( counter == 8 ) {
      counter_for_matrixs_wise = 0;  
    } 

  }

  next_line
  std::vector<std::vector<double>> main_diameters { vec_main_diameter_of_double_matrix ( double_matrix ) };
  std::vector<std::vector<double>> side_diameters { vec_side_diameter_of_double_matrix( double_matrix ) };
  std::vector<double> multiplication_main_diameters {};
  std::vector<double> multiplication_side_diameters {};
  double total_of_the_main_diameters { 0 };
  double total_of_the_side_diameters { 0 };

  std::cout << main_diameters[ 0 ][ 0 ] * main_diameters[ 0 ][ 1 ] * main_diameters[ 0 ][ 2 ] << '\n';
  std::cout << main_diameters[ 1 ][ 0 ] * main_diameters[ 1 ][ 1 ] * main_diameters[ 1 ][ 2 ] << '\n';
  std::cout << main_diameters[ 2 ][ 0 ] * main_diameters[ 2 ][ 1 ] * main_diameters[ 2 ][ 2 ] << '\n';
  next_line
  double number_of_each_main_and_side_diameter { 1 };

  for ( int counter { 0 }; counter < 3; ++ counter ) {
    number_of_each_main_and_side_diameter = 1;

    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      number_of_each_main_and_side_diameter *= main_diameters[ counter ][ nested_counter ];
    }
    
    multiplication_main_diameters.push_back( number_of_each_main_and_side_diameter );

  }


  for ( int counter { 0 }; counter < 3; ++ counter ) {
    number_of_each_main_and_side_diameter = 1;

    for ( int nested_counter { 0 }; nested_counter < 3; ++ nested_counter ) {
      number_of_each_main_and_side_diameter *= side_diameters[ counter ][ nested_counter ];
    }
    
    multiplication_side_diameters.push_back( number_of_each_main_and_side_diameter );

  }


  next_line

  for ( int counter { 0 }; counter < 3; ++ counter ) {
    std::cout << multiplication_main_diameters[ counter ] << '\t';
    total_of_the_main_diameters += multiplication_main_diameters[ counter ];
  }

  next_line

  for ( int counter { 0 }; counter < 3; ++ counter ) {
    std::cout << multiplication_side_diameters[ counter ] << '\t';
    total_of_the_side_diameters += multiplication_side_diameters[ counter ];
  }


return total_of_the_main_diameters - total_of_the_side_diameters;
}

double matrixs_detarmination_expantion_mathod() {

  
}



double matrix_detrmination_operation( std::vector<std::vector<double> > square_matrixs_lines_and_columns , std::vector<double> matrixs_wise ) {
  double det {};

  if ( square_matrixs_lines_and_columns[ 0 ][ 0 ] == 1 ) {
    det = matrixs_wise[ 0 ];
  }

  else {
    
    if ( square_matrixs_lines_and_columns[ 0 ][ 0 ] == 2 ) {
      det = detarmination_for_2_by_2_matrix( matrixs_wise );
    }

    else if ( square_matrixs_lines_and_columns[ 0 ][ 0 ] == 3 ) {
      det = matrixs_detarmination_in_rule_of_sarrus( matrixs_wise , square_matrixs_lines_and_columns );
    }

    else {

    }

  }

return det;
}



int matrix_determination( std::vector<std::vector<double> > square_matrixs_lines_and_columns , std::vector<double> matrixs_wise ) {
  next_line
  std::vector<std::vector<double>> matrix_in_vec_2D ( square_matrixs_lines_and_columns[ 0 ][ 1 ] );
  int counter_for_matrixs_wise { 0 };

  for ( int counter { 0 }; counter <  matrix_in_vec_2D.size(); ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < square_matrixs_lines_and_columns[ 0 ][ 1 ]; ++ nested_counter ) {
      matrix_in_vec_2D[ counter ].push_back( matrixs_wise[ counter_for_matrixs_wise ] );

    }
    
    std::cout << '\n';

  }

  counter_for_matrixs_wise = 0;

  std::cout << "The matrix is : " << '\n';
  next_line
 
  for ( int counter { 0 }; counter < square_matrixs_lines_and_columns[ 0 ][ 0 ]; ++ counter ) {
    
    for ( int nested_counter { 0 }; nested_counter < square_matrixs_lines_and_columns[ 0 ][ 1 ]; ++ nested_counter ) {
      std::cout << matrixs_wise[ counter_for_matrixs_wise ] << '\t';
      ++ counter_for_matrixs_wise;
    }

    std::cout << '\n';
  }

  double det { matrix_detrmination_operation( square_matrixs_lines_and_columns , matrixs_wise ) };


return det;
}

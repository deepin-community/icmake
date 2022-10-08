//#define XERR
#include "dependencies.ih"

void Dependencies::showDependencies(char const *label) const
{
    if (d_options.verbosity() < 3)
        return;

    size_t col1width = d_dirWidth + 4;

    cout << '\n' << label << '\n';

    tableLine(0, col1width + d_size * 3);   // 3 positions per class index


    cout << setw(col1width) << ' ' << "uses:\n";

    tableLine(col1width,  d_size * 3);

    cout << setw(d_dirWidth) << "class:" << "    ";
    numberLine(d_size);

    tableLine(0, col1width + d_size * 3); 

        // element [row][col] indicates whether directory row uses directory
        // col, which implies that col's being used by row
        // By visiting all elements in column col all directories that use col
        // are found
    for (size_t row = 0; row != d_size; ++row)
    {
        unsigned rowIdx = d_classIdx[row];

        cout << setw(d_dirWidth) << d_directory[rowIdx] << ' ' << 
                                    setw(2) << (row + 1) << ' ';
        
        BoolVect const &rowVect = d_dependency[rowIdx];

        for (size_t col = 0; col != row; ++col)
            cout << (rowVect[d_classIdx[col]] ?  " x " : "   ");

                                                // diagonal element
        cout << (rowVect[d_classIdx[row]] ?  " x " : " - ");

        for (size_t col = row + 1; col != d_size; ++col)
            cout << (rowVect[d_classIdx[col]] ?  " x " : "   ");

//        for (size_t col = 0; col != d_size; ++col)
//            cout << (rowVect[d_classIdx[col]] ?  " x " : "   ");

        cout.put('\n');
    }

    tableLine(0, col1width + d_size * 3);

    cout << setw(col1width) << ' ';
    numberLine(d_size);

    tableLine(0, col1width + d_size * 3); 
        
    cout.put('\n');
}

//  Before 10.00.00: showing 'used by' instead of 'uses':
//
//        // element [d1][d2] indicates whether directory d1 uses directory d2.
//        // which amounts to d2 being used by d1
//        // By visiting all elements in column d2 all directories that use d2
//        // are found
//    for (size_t d2 = 0; d2 != d_size; ++d2)
//    {
//        cout << setw(d_dirWidth) << d_directory[d2] << ' ' << 
//                                                setw(2) << (d2 + 1) << ' ';
//        
//        for (size_t d1 = 0; d1 != d_size; ++d1)
//            cout << (d_dependency[d1][d2] ?  " x " : "   ");
//
//        cout.put('\n');
//    }



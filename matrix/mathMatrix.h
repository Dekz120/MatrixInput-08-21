#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



template <class MATRIX_ELEM>
class mathMatrix{
public:
/// Constructors/redefinitions


    mathMatrix(){matrixField = nullptr;}; // c
    ~mathMatrix(){delete matrixField;}
    mathMatrix(const int line, const int column): lineSize(line), columnSize(column)
    {
        matrixField = new vector<MATRIX_ELEM > (line * column, NULL);

    };

    mathMatrix(const mathMatrix& m):  lineSize (m.lineSize), columnSize(m.columnSize)
    {
        matrixField = new vector<MATRIX_ELEM > (*m.matrixField);
        cout << "mathMatrix cpy constructor" << endl;
    }
    mathMatrix(mathMatrix&& m):  lineSize (m.lineSize), columnSize(m.columnSize), matrixField(m.matrixField)
    {
        m.matrixField = nullptr;
        cout << "mathMatrix move constructor" << endl;
    }
    ////
    void mtrxResize(const int line, const int column)
    {
        delete matrixField;
        matrixField = new vector<MATRIX_ELEM > (line * column, NULL);
        lineSize = line;
        columnSize = column;
    }


/// Overload math(+-*/) / unary matrix operations
    mathMatrix operator +(const mathMatrix& matr2)
    {
        mathMatrix tmpMatrx(lineSize, columnSize);
        for(int i=0; i < lineSize*columnSize; i++)
        {
            (*tmpMatrx.matrixField)[i] = (*matrixField)[i] + (*matr2.matrixField)[i];
        }
        return tmpMatrx;

    }
    mathMatrix operator -(const mathMatrix& matr2)
    {
        mathMatrix tmpMatrx(lineSize, columnSize);
        for(int i=0; i < lineSize*columnSize; i++)
        {
            (*tmpMatrx.matrixField)[i] = (*matrixField)[i] - (*matr2.matrixField)[i];
        }
        return tmpMatrx;

    }
    ///
    mathMatrix operator *(const mathMatrix& matr2)
    {
        mathMatrix tmpMatrx(matr2.getLineSize(), matr2.getColumnSize());
        int string_elem = 0;
        int column_elem = 0;
        for(int index=0; index < matr2.size(); index++ )
        {
            MATRIX_ELEM tmp=0;
            for(int i = string_elem, j = column_elem, k=0; k < this->getLineSize(); i++, j++, k++)
            {
                tmp += (*matrixField)[i] * (*matr2.matrixField)[j + k*(matr2.getLineSize()-1)] ;

            }
            cout << index << ' ' << tmp << endl;
            (*tmpMatrx.matrixField)[index] = tmp ;

            if(column_elem == matr2.getLineSize() - 1)
            {
                cout<< "rught" << endl;
               column_elem = 0; string_elem += this->getLineSize();
            }
            else {column_elem++;}
        }
        return tmpMatrx;
    }
    ////
    mathMatrix operator *(const MATRIX_ELEM var)
    {
        mathMatrix tmpMatrx(this->getLineSize(), this->getColumnSize());
        for(int i=0; i < tmpMatrx.size(); i++)
        {
            (*tmpMatrx.matrixField)[i] = (*this->matrixField)[i] * var;
        }
        return tmpMatrx;
    }
    ////
    mathMatrix operator /(const MATRIX_ELEM var)
    {
        mathMatrix tmpMatrx(this->getLineSize(), this->getColumnSize());
        *this * (1/var);
    }
    ////
    mathMatrix& operator =(const mathMatrix& m)
    {
        if(&m == this) {return *this;}
        delete matrixField;
        matrixField = new vector<MATRIX_ELEM >;
        *matrixField = *m.matrixField;
        return* this;
    }
     mathMatrix& operator =(mathMatrix&& m)
    {
        if(&m == this) {return *this;}
        delete matrixField;
        lineSize = m.lineSize; columnSize =m.columnSize;
        matrixField = m.matrixField;
        m.matrixField = nullptr;
        cout << "Math move =" << endl;

        return *this;
    }

    ///
    friend mathMatrix transposit(const mathMatrix& matr)
    {
        mathMatrix tmpMatrix(matr.getColumnSize(), matr.getLineSize());

        int string_elem = 0;
        int column_elem = 0;
        for(int i =0; i < matr.size(); i++)
        {
            string_elem = i / matr.getLineSize() + 1;
            column_elem = i % matr.getLineSize() + 1;
            tmpMatrix.addElem(column_elem, string_elem, (*matr.matrixField)[i]);

        }
        return tmpMatrix;
    }
    ////
    friend mathMatrix CutMinorMatrix(const mathMatrix& matr, int i_line, int j_col) //remember, 1 in matrix equal 0 on []
    {
        mathMatrix tmp_matrix(matr.getLineSize()-1, matr.getColumnSize()-1);

        int string_elem;
        int column_elem;

        for(int i = 0, index = 0; i < tmp_matrix.size(); index++)
        {
            string_elem = index / matr.getLineSize() + 1;
            column_elem = index % matr.getLineSize() + 1;
            //cout << string_elem << ' ' << column_elem << endl;

            if(string_elem != i_line && column_elem != j_col)
            {
                (*tmp_matrix.matrixField)[i++]= (*matr.matrixField)[index];
            }
        }

        return tmp_matrix;

    }
    ////

    friend MATRIX_ELEM findDefinitor(const mathMatrix&& matr) // here i'am finding definitor by 1t colimn minor matrix
    {
        long double definitor=0;
        if(matr.getLineSize() == 2 && matr.getColumnSize()==2)
        {
            definitor = (*matr.matrixField)[0] * (*matr.matrixField)[3] - (*matr.matrixField)[1] * (*matr.matrixField)[2];
        }
        else // matrix size is bigger than 2
        {
            for(int index=0, parity = 0; index < matr.size() - matr.getColumnSize() + 1; index += matr.getLineSize(), parity++)
            {
                if(parity % 2 == 0)
                {
                    definitor += (*matr.matrixField)[index] *
                    findDefinitor(CutMinorMatrix(matr, index  / matr.getLineSize() + 1, index  % matr.getLineSize() + 1));
                }
                else
                {
                    definitor -= (*matr.matrixField)[index] *
                    findDefinitor(CutMinorMatrix(matr, index  / matr.getLineSize() + 1, index  % matr.getLineSize() + 1));
                }
            }
        }

        return definitor;
    }
    ////
    friend mathMatrix builtMinorMatrix(const mathMatrix& matr, MATRIX_ELEM& definitor)
    {
        definitor = findDefinitor(std::move(matr));
        if(definitor == 0) {
            mathMatrix tmp_matrix(matr.getLineSize()-1, matr.getColumnSize()-1);
            return tmp_matrix;}
        else
        {
            mathMatrix tmp_matrix(matr.getLineSize(), matr.getColumnSize());
            for (int index =0; index < tmp_matrix.size(); index++)
            {
                if(index % 2 == 0)
                {
                    (*tmp_matrix.matrixField)[index] = findDefinitor(CutMinorMatrix(matr, index  / matr.getLineSize() + 1, index  % matr.getLineSize() + 1));
                }
                else
                {
                    (*tmp_matrix.matrixField)[index] = 0 - findDefinitor(CutMinorMatrix(matr, index  / matr.getLineSize() + 1, index  % matr.getLineSize() + 1));
                }
            }
            return tmp_matrix;
        }
    }
    ////
    friend mathMatrix Reverse(const mathMatrix& matr) // not exaclty
    {
        mathMatrix tmp_matrix;
        MATRIX_ELEM definitor;
        tmp_matrix = builtMinorMatrix(matr, definitor);
        if(definitor != 0)
        {
            tmp_matrix = transposit(tmp_matrix) * (1 / definitor);
        }
        else {tmp_matrix.mtrxResize(1,1);}
        return tmp_matrix;
    }
    mathMatrix operator/(const mathMatrix& matr2)
    {
        mathMatrix tmpMatrx(matr2.getLineSize(), matr2.getColumnSize());
        tmpMatrx = *this * Reverse(matr2);
        return tmpMatrx;
    }
    ///
    ///
    MATRIX_ELEM getElem(const int i_line, const int j_column)
    {
        return (*matrixField)[lineSize*(i_line - 1) + (j_column-1)];
    }
    ///
    MATRIX_ELEM getElem(const int index)
    {
        return (*matrixField)[index];
    }
    ///
    int addElem(const int i_line, const int j_column, const MATRIX_ELEM mVal)
    {
        int mIndex = lineSize*(i_line - 1) + (j_column-1) ;
        if(mIndex < 0 && mIndex > lineSize*columnSize-1)
        {
            cout << "Out of range" << endl;return -1;
        }
        (*matrixField)[lineSize*(i_line - 1) + (j_column-1) ] = mVal;
        return 0;
    }
    int addElem(const int mIndex, const MATRIX_ELEM mVal)
    {
        if(mIndex < 0 && mIndex > lineSize*columnSize-1)
        {
            cout << "Out of rangeE" << endl;return -1;
        }
        (*matrixField)[mIndex] = mVal;
        return 0;
    }
    ///
    int size() const
    {
        return matrixField->size();
    }
    ///
    int getLineSize() const {return lineSize;};
    int getColumnSize()const {return columnSize;};
private:
    vector<MATRIX_ELEM> *matrixField;
    int lineSize, columnSize;
};





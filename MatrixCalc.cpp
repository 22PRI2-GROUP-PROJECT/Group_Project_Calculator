//Realised by Machehin Grigory Alexandrovich
#include "MatrixCalc.h"

// ������� ��� ����� �������
void inputMatrix(double matrix[][MAX_SIZE], int rows, int cols)
{
    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// ������� ��� ������ �������
void printMatrix(double matrix[][MAX_SIZE], int rows, int cols)
{
    cout << "�������: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ������� ��� �������� ������
void addMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// ������� ��� ��������� ������
void subtractMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// ������� ��� ��������� ������
void multiplyMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// ������� ��� ������� ������
void divideMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] / matrix2[i][j];
        }
    }
}

void SumMatrNum(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols) {
    int num;
    cout << "����� = "; cin >> num;
    cout << "��������� �������� ������� � ������:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + num;
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ��������� ����� �� �������
void SubstractMatrNum(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols) {
    int num;
    cout << "����� = "; cin >> num;
    cout << "��������� ��������� ����� �� �������:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - num;
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ��������� ������� �� �����
void MultiplyNumber(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols) {
    int num;
    cout << "����� = "; cin >> num;
    cout << "��������� ��������� ����� �� �������:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] * num;
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

void MatrTransp(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols) {
    cout << "����������������� �������:" << endl;
    int trans[5][5];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = matrix1[i][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << trans[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ���������� ������������ �������
int MatrDeterm(double matrix1[][MAX_SIZE], int rows, int cols) {
    double det = 0;
    double subMat[MAX_SIZE][MAX_SIZE];
    if (rows == 1) {
        return matrix1[0][0];
    }
    else if (rows == 2) {
        return matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
    }
    else {
        for (int x = 0; x < rows; x++) {
            int subi = 0;
            for (int i = 1; i < rows; i++) {
                int subj = 0;
                for (int j = 0; j < rows; j++) {
                    if (j == x) {
                        continue;
                    }
                    subMat[subi][subj] = matrix1[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix1[0][x] * MatrDeterm(subMat, rows - 1, cols);
        }
    }
    return det;
}

void MatrReverse(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols) {
    double det = MatrDeterm(matrix1, rows, cols);
    double transpForInverse[MAX_SIZE][MAX_SIZE];

    if (rows != cols) {
        cout << "�������� ������� �� ����������, ������ ��� ���������� ����� �� ����� ���������� �����" << endl << endl;
        return;
    }
    if (det == 0) {
        cout << "�������� ������� �� ����������, ������ ��� ����������� = 0" << endl << endl;
        return;
    }
    double inv[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double subMat[MAX_SIZE][MAX_SIZE];
            int subi = 0;
            for (int m = 0; m < rows; m++) {
                if (m == i) {
                    continue;
                }
                int subj = 0;
                for (int k = 0; k < rows; k++) {
                    if (k == j) {
                        continue;
                    }
                    subMat[subi][subj] = matrix1[m][k];
                    subj++;
                }
                subi++;
            }
            inv[i][j] = (j % 2 == 0 ? 1 : -1) * (i % 2 == 0 ? 1 : -1) * MatrDeterm(subMat, rows - 1, cols);
        }
    }
    MatrTransp(inv, transpForInverse, rows, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            inv[i][j] /= det;
        }
    }
    cout << "�������� �������:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cout << inv[i][j] << "\t";
        }
        cout << endl;
    }
}

void MatrMenu()
{
    system("cls");
    int rows1, cols1, rows2, cols2, choice, mainChoice;
    double matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];

    do
    {
        cout << "1. ������ ������ �������" << endl;
        cout << "0. ����� � ����" << endl;
        cin >> mainChoice;
        switch (mainChoice)
        {
        case 0: return;
        default: cout << "������������ ����� ��������" << endl; break;
        }




        do
        {
            system("cls");
            cout << "���������� ����� ������ ������� ->  ";
            cin >> rows1;
            cout << "���������� �������� ������ ������� ->  ";
            cin >> cols1;
        } while (rows1 < 1 || cols1 < 1);


        inputMatrix(matrix1, rows1, cols1);
        printMatrix(matrix1, rows1, cols1);

        do
        {
            cout << "�������� �������� ��� ����������: " << endl;
            cout << "1. ��������� �������" << endl;
            cout << "2. ������� �������" << endl;
            cout << "3. �������� �� �������" << endl;
            cout << "4. ��������� ����� � �������" << endl;
            cout << "5. ������� ����� �� �������" << endl;
            cout << "6. �������� ������� �� �����" << endl;
            cout << "7. ��������������� �������" << endl;
            cout << "8. ����� �������� �������" << endl;
            cout << "9. ����� ������������ �������" << endl;
            cout << "0. �����/������ ����� �������" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                do
                {
                    cout << "���������� ����� ������ ������� ->  ";
                    cin >> rows2;
                    cout << "���������� �������� ������ ������� ->  ";
                    cin >> cols2;
                } while (rows2 < 1 || cols2 < 1);

                if (rows1 != rows2 || cols1 != cols2)
                {
                    cout << "������� ������ �� ���������, �������� ����������" << endl;
                    break;
                }
                inputMatrix(matrix2, rows2, cols2);
                printMatrix(matrix2, rows2, cols2);

                double sumMatrix[MAX_SIZE][MAX_SIZE];
                addMatrix(matrix1, matrix2, sumMatrix, rows1, cols1);
                printMatrix(sumMatrix, rows1, cols1);
                break;

            case 2:
                do
                {
                    cout << "���������� ����� ������ ������� ->  ";
                    cin >> rows2;
                    cout << "���������� �������� ������ ������� ->  ";
                    cin >> cols2;
                } while (rows2 < 1 || cols2 < 1);
                if (rows1 != rows2 || cols1 != cols2)
                {
                    cout << "������� ������ �� ���������, ��������� ����������" << endl << endl;
                    break;
                }
                inputMatrix(matrix2, rows2, cols2);
                printMatrix(matrix2, rows2, cols2);

                double diffMatrix[MAX_SIZE][MAX_SIZE];
                subtractMatrix(matrix1, matrix2, diffMatrix, rows1, cols1);
                printMatrix(diffMatrix, rows1, cols1);
                break;

            case 3:
                do
                {
                    cout << "���������� ����� ������ ������� ->  ";
                    cin >> rows2;
                    cout << "���������� �������� ������ ������� ->  ";
                    cin >> cols2;
                } while (rows2 < 1 || cols2 < 1);

                if (cols1 != rows2)
                {
                    cout << "���������� �������� ������ ������� �� ��������� � ����������� ����� ������ �������, ��������� ����������" << endl << endl;
                    break;
                }
                inputMatrix(matrix2, rows2, cols2);
                printMatrix(matrix2, rows2, cols2);

                double prodMatrix[MAX_SIZE][MAX_SIZE];
                multiplyMatrix(matrix1, matrix2, prodMatrix, rows1, cols1, cols2);
                printMatrix(prodMatrix, rows1, cols2);
                break;
            case 4:
                double sumNumMatrix[MAX_SIZE][MAX_SIZE];
                SumMatrNum(matrix1, sumNumMatrix, rows1, cols1);
                break;
            case 5:
                double substractNumMatrix[MAX_SIZE][MAX_SIZE];
                SubstractMatrNum(matrix1, sumNumMatrix, rows1, cols1);
                break;
            case 6:
                double multiplNumMatrix[MAX_SIZE][MAX_SIZE];
                MultiplyNumber(matrix1, multiplNumMatrix, rows1, cols1);
                break;
            case 7:
                double transpMatrix[MAX_SIZE][MAX_SIZE];
                MatrTransp(matrix1, transpMatrix, rows1, cols1);
                break;
            case 8:
                double inverseMatrix[MAX_SIZE][MAX_SIZE];
                MatrReverse(matrix1, inverseMatrix, rows1, cols1);
            case 9:
                cout << "������������ �������: " << MatrDeterm(matrix1, rows1, cols1) << endl << endl;
                break;
            case 0:
                break;

            default:
                cout << "������������ ����� ��������" << endl;
                break;
            }
        } while (choice != 0);
    } while (mainChoice != 0);
    return;
}
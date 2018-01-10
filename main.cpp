#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;



int main()
{
    int contador = 0;
    int D = 0;
    int M = 0;
    int L;
    int LC = 2;
    int R = 0;
    int columnas = 800;
    int filas = 800;
    int nodo = 13;
    int elementos = 16;
    int nodosFijos = 2;
    int vueltas;
    int encontro = 0;
    int auxiliar_2 = 0;
    double longitud = 300;
    double centrar = 380;
    double longitud_2 = 350;
    double centrar_2 = 380;
    double longitud_3 = 300;
    double centrar_3 = 380;
    double longitud_4 = 350;
    double centrar_4 = 380;
    double suma = 0;
    double A = 0;
    double auxiliar = 0;
    string S;
    string N;

    int matriz_nodoLocal[elementos][3];       // Lista de los nodos de cada elemento
    int Lista_nodosFijos[nodosFijos];
    double coordenadas_X[nodo];
    double coordenadas_Y[nodo];
    double Valor_nodosFijos[nodosFijos];
    double matriz_CE[3][3];
    double matriz_C[nodo][nodo];
    double matrizL[nodo][nodo];
    double matrizU[nodo][nodo];
    double ID[elementos][3];
    double Valores_Jacobianos[elementos];
    double Area[elementos];
    double B[nodo];
    double XL[3];
    double YL[3];
    double a[3];
    double b[3];
    double c[3];
    double P[3];
    double Q[3];
    double X[nodo];
    double Y[nodo];

    cout << "\n";
    cout << "Dame el numero total de Inyecciones: " << endl;
    cin >> vueltas;

    cout << "\n";
    cout << "Cuantos electrodos en total tienes?: " << endl;
    cin >> L;

    D = vueltas;
    M = L - LC;
    R = D * M;

    cout << "\n";
    cout << "**************************************************" << endl;
    cout << "LA MATRIZ JACOBIANA TENDRA UN TAMANO DE: " << endl;
    cout << R << " x " << elementos << endl;
    cout << "**************************************************" << endl;
    cout << "\n";

    double Auxiliar_J[D][M];
    double Guardar_Valor[R];
    double Jacobiano[R][elementos];
    double matrizX[nodo][vueltas];
    double matrizI[nodo][vueltas];
    double matriz_Id[elementos][vueltas];
    double matriz_Im[elementos][vueltas];

    for(int e = 0; e < elementos; e++)
    {
        for(int j = 0; j < 3; j++)
        {
            ID[e][j] = 0;
        }
    }

    for(int e = 0; e < elementos; e++)
    {
        for(int j = 0; j < vueltas; j++)
        {
            matriz_Id[e][j] = 0;
            matriz_Im[e][j] = 0;
        }
    }

    for(int d = 0; d < R; d++)
    {
        for(int x = 0; x < elementos; x++)
        {
            Jacobiano[d][x] = 0;
        }
    }

    for(int d = 0; d < nodo; d++)
    {
        for(int g = 0; g < vueltas; g++)
        {
            matrizX[d][g] = 0;
            matrizI[d][g] = 0;
        }
    }

    for(int parar = 0; parar < vueltas; parar++)
    {
         Mat img(filas, columnas, CV_8UC3, Scalar::all(255));

        for(int h = 0; h < nodo; h++)
        {
            X[h] = 0;
            Y[h] = 0;
            B[h] = 0;
            for(int g = 0; g < nodo; g++)
            {
                matriz_C[h][g] = 0;
                matrizL[h][g] = 0;
                matrizU[h][g] = 0;
            }
        }

    matriz_nodoLocal[0][0] = 1;
    matriz_nodoLocal[0][1] = 10;
    matriz_nodoLocal[0][2] = 9;

    matriz_nodoLocal[1][0] = 1;
    matriz_nodoLocal[1][1] = 2;
    matriz_nodoLocal[1][2] = 10;

    matriz_nodoLocal[2][0] = 3;
    matriz_nodoLocal[2][1] = 10;
    matriz_nodoLocal[2][2] = 2;

    matriz_nodoLocal[3][0] = 13;
    matriz_nodoLocal[3][1] = 10;
    matriz_nodoLocal[3][2] = 11;

    matriz_nodoLocal[4][0] = 3;
    matriz_nodoLocal[4][1] = 11;
    matriz_nodoLocal[4][2] = 10;

    matriz_nodoLocal[5][0] = 3;
    matriz_nodoLocal[5][1] = 4;
    matriz_nodoLocal[5][2] = 11;

    matriz_nodoLocal[6][0] = 13;
    matriz_nodoLocal[6][1] = 11;
    matriz_nodoLocal[6][2] = 12;

    matriz_nodoLocal[7][0] = 5;
    matriz_nodoLocal[7][1] = 11;
    matriz_nodoLocal[7][2] = 4;

    matriz_nodoLocal[8][0] = 5;
    matriz_nodoLocal[8][1] = 12;
    matriz_nodoLocal[8][2] = 11;

    matriz_nodoLocal[9][0] = 5;
    matriz_nodoLocal[9][1] = 6;
    matriz_nodoLocal[9][2] = 12;

    matriz_nodoLocal[10][0] = 7;
    matriz_nodoLocal[10][1] = 12;
    matriz_nodoLocal[10][2] = 6;

    matriz_nodoLocal[11][0] = 13;
    matriz_nodoLocal[11][1] = 12;
    matriz_nodoLocal[11][2] = 9;

    matriz_nodoLocal[12][0] = 7;
    matriz_nodoLocal[12][1] = 9;
    matriz_nodoLocal[12][2] = 12;

    matriz_nodoLocal[13][0] = 7;
    matriz_nodoLocal[13][1] = 8;
    matriz_nodoLocal[13][2] = 9;

    matriz_nodoLocal[14][0] = 13;
    matriz_nodoLocal[14][1] = 9;
    matriz_nodoLocal[14][2] = 10;

    matriz_nodoLocal[15][0] = 1;
    matriz_nodoLocal[15][1] = 9;
    matriz_nodoLocal[15][2] = 8;

    coordenadas_X[0] = 0;
    coordenadas_Y[0] = 1;

    coordenadas_X[1] = -0.75;
    coordenadas_Y[1] = 0.75;

    coordenadas_X[2] = -1;
    coordenadas_Y[2] = 0;

    coordenadas_X[3] = -0.75;
    coordenadas_Y[3] = -0.75;

    coordenadas_X[4] = 0;
    coordenadas_Y[4] = -1;

    coordenadas_X[5] = 0.75;
    coordenadas_Y[5] = -0.75;

    coordenadas_X[6] = 1;
    coordenadas_Y[6] = 0;

    coordenadas_X[7] = 0.75;
    coordenadas_Y[7] = 0.75;

    coordenadas_X[8] = 0.35;
    coordenadas_Y[8] = 0.35;

    coordenadas_X[9] = -0.35;
    coordenadas_Y[9] = 0.35;

    coordenadas_X[10] = -0.35;
    coordenadas_Y[10] = -0.35;

    coordenadas_X[11] = 0.35;
    coordenadas_Y[11] = -0.35;

    coordenadas_X[12] = 0;
    coordenadas_Y[12] = 0;

    for(int i = 0; i < elementos; i++)
    {
        encontro = 0;
        for(int j = 0; j < 3; j++)
        {
            encontro = matriz_nodoLocal[i][j];
            XL[j] = coordenadas_X[encontro - 1];
            YL[j] = coordenadas_Y[encontro - 1];
        }

            line(img, Point ((XL[0] * longitud) + centrar, (-YL[0] * longitud) + centrar),Point((XL[1] * longitud) + centrar, (-YL[1] * longitud) + centrar), CV_RGB(0,255,0), 3, CV_AA);
            line(img, Point ((XL[1] * longitud) + centrar, (-YL[1] * longitud) + centrar),Point((XL[2] * longitud) + centrar, (-YL[2] * longitud) + centrar), CV_RGB(0,255,0), 3, CV_AA);
            line(img, Point ((XL[2] * longitud) + centrar, (-YL[2] * longitud) + centrar),Point((XL[0] * longitud) + centrar, (-YL[0] * longitud) + centrar), CV_RGB(0,255,0), 3, CV_AA);

            P[0] = (YL[1] - YL[2]);
            P[1] = (YL[2] - YL[0]);
            P[2] = (YL[0] - YL[1]);

            Q[0] = (XL[2] - XL[1]);
            Q[1] = (XL[0] - XL[2]);
            Q[2] = (XL[1] - XL[0]);

            a[0] = ((XL[1] * YL[2])-(XL[2] * YL[1]));
            b[0] = P[0];
            c[0] = Q[0];

            a[1] = ((XL[2] * YL[0])-(XL[0] * YL[2]));
            b[1] = P[1];
            c[1] = Q[1];

            a[2] = ((XL[0] * YL[1])-(XL[1] * YL[0]));
            b[2] = P[2];
            c[2] = Q[2];

            A = (0.5)*(((P[1] * Q[2]) - (P[2] * Q[1])));

            Area[i] = A;

            a[0] = a[0] / (2*A);
            b[0] = b[0] / (2*A);
            c[0] = c[0] / (2*A);

            a[1] = a[1] / (2*A);
            b[1] = b[1] / (2*A);
            c[1] = c[1] / (2*A);

            a[2] = a[2] / (2*A);
            b[2] = b[2] / (2*A);
            c[2] = c[2] / (2*A);

            for(int g = 0; g < 3; g++)
            {
                ID[i][g] = b[g] + c[g];
            }

            for(int i = 0; i < 3; i++)
            {
                auxiliar = 0;
                for(int j = 0; j < 3; j++)
                {
                    auxiliar = ((P[i]*P[j]) + (Q[i]*Q[j]));
                    matriz_CE[i][j] = auxiliar / (4*A);
                }
            }

                encontro = 0;
                for(int y = 0; y < 3; y++)
                {
                    encontro = matriz_nodoLocal[i][y];
                    for(int H = 0; H < 3; H++)
                    {
                        auxiliar_2 = 0;
                        auxiliar_2 = matriz_nodoLocal[i][H];
                        matriz_C[encontro - 1][auxiliar_2 - 1] = matriz_C[encontro - 1][auxiliar_2 - 1] + matriz_CE[y][H];
                    }
                }
    }

            matriz_C[nodo - 1][nodo - 1] = 1;

            for(int i = 0; i <= nodo - 2; i++)
            {
                matriz_C[nodo - 1][i] = 0;
            }

                for(int i = 0; i <= nodo - 2; i++)
                {
                    matriz_C[i][nodo - 1] = 0;
                }

            cout << "\n\n";
            cout << "******* MATRIZ INVERSA GLOBAL DEL PROBLEMA *******" << endl;
            for(int i = 0; i < nodo; i++)
            {
                cout << "\n";
                cout << "|\t";
                for(int j = 0; j < nodo; j++)
                {
                    printf("%.2f\t", matriz_C[i][j]);
                }
                    printf("   |\t");
            }

            cout << "\n\n";

            for(int i = 0; i < nodosFijos; i++)
            {
                cout << "Dame el electrodo[" << i + 1 << "]:" << endl;
                cin >> Lista_nodosFijos[i];
            }

                for(int i = 0; i < nodosFijos; i++)
                {
                    cout << "Dame el valor de la corriente del electrodo[" << i + 1 << "]:" << endl;
                    cin >> Valor_nodosFijos[i];
                }

                for(int u = 0; u < elementos; u++)
                {
                    encontro = 0;
                    for(int t = 0; t < 3; t++)
                    {
                         encontro = matriz_nodoLocal[u][t];
                         for(int v = 0; v < nodosFijos; v++)
                         {
                             if(encontro == Lista_nodosFijos[v])
                             {
                                 B[encontro - 1] = Valor_nodosFijos[v];
                             }
                         }
                    }
                }

                for(int t = 0; t < nodo; t++)
                {
                    matrizI[t][parar] = B[t];
                }

                for(int i = 0; i < nodo; i++)
                {
                    matrizL[i][i] = 1;
                }

                matrizU[0][0] = matriz_C[0][0];

                for(int j = 1; j < nodo; j++)
                {
                    matrizU[0][j] = matriz_C[0][j] / matrizL[0][0];
                    matrizL[j][0] = matriz_C[j][0] / matrizU[0][0];
                }
                    for(int i = 1; i < nodo - 1; i++)
                    {
                        suma = 0;
                        for(int k = 0; k <= i - 1; k++)
                        {
                            suma = suma + (matrizL[i][k] * matrizU[k][i]);
                        }
                            matrizU[i][i] = matriz_C[i][i] - suma;

                            for(int j = i + 1; j < nodo; j++)
                            {
                                suma = 0;
                                auxiliar = 0;
                                for(int k = 0; k <= i - 1; k++)
                                {
                                    suma = suma + (matrizL[i][k] * matrizU[k][j]);
                                    auxiliar = auxiliar + (matrizL[j][k] * matrizU[k][i]);
                                }
                                    suma = matriz_C[i][j] - suma;
                                    auxiliar = matriz_C[j][i] - auxiliar;

                                    matrizU[i][j] = (suma / matrizL[i][i]);
                                    matrizL[j][i] = (auxiliar / matrizU[i][i]);
                            }
                    }

                    suma = 0;
                    for(int k = 0; k < nodo - 1; k++)
                    {
                        suma = suma + (matrizL[nodo - 1][k] * matrizU[k][nodo - 1]);
                    }
                        matrizU[nodo - 1][nodo - 1] = matriz_C[nodo - 1][nodo - 1] - suma;

                    Y[0] = B[0] / matrizL[0][0];

                    for(int i = 1; i < nodo; i++)
                    {
                        suma = 0;
                        for(int j = 0; j <= i - 1; j++)
                        {
                            suma = suma + (matrizL[i][j] * Y[j]);
                        }
                            suma = B[i] - suma;
                            Y[i] = suma / matrizL[i][i];
                    }

                        X[nodo - 1] = Y[nodo - 1] / matrizU[nodo - 1][nodo - 1];

                        for(int i = nodo - 2; i >= 0; i--)
                        {
                            suma = 0;
                            for(int j = i + 1; j < nodo; j++)
                            {
                                suma = suma + (matrizU[i][j] * X[j]);
                            }
                                suma = Y[i] - suma;
                                X[i] = suma / matrizU[i][i];
                        }

                        for(int r = 0; r < nodo; r++)
                        {
                            matrizX[r][parar] = X[r];
                        }

                    cout << "\n\n";
                    cout << "\t Vuelta N.- " << parar + 1 << endl;
                    cout << "   Potenciales de los Nodos   ";
                    cout << "\n";
                    for(int n = 0; n < nodo; n++)
                    {
                        stringstream ss;
                        ss << fixed << setprecision(2) << X[n];
                        S = ss.str();
                        putText(img, S, Point((coordenadas_X[n] * longitud_3) + centrar_3, (-coordenadas_Y[n] * longitud_3) + centrar_3), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(250,0,0), 2);
                        cout << "\n";
                        cout << "|\t";
                        cout << "Nodo " << n + 1 << " = ";
                        printf("%.2f\t", X[n]);
                        cout << ("     |\t");
                    }

                    for(int y = 0; y < 8; y++)
                    {
                        stringstream nn;
                        nn << fixed << y + 1;
                        N = nn.str();
                        putText(img, N, Point((coordenadas_X[y] * longitud_4) + centrar_4, (-coordenadas_Y[y] * longitud_4) + centrar_4), FONT_HERSHEY_SCRIPT_COMPLEX, 0.8, CV_RGB(0,0,0), 1.5);
                        circle(img, Point((coordenadas_X[y] * longitud_2) + centrar_2, (-coordenadas_Y[y] * longitud_2) + centrar_2), 20, CV_RGB(255,0,0), 3);
                    }

                    for(int i = 0; i < elementos; i++)
                    {
                        encontro = 0;
                        for(int j = 0; j < 3; j++)
                        {
                            encontro = matriz_nodoLocal[i][j];
                            ID[i][j] = ID[i][j] * X[encontro - 1];
                        }
                    }

                    for(int i = 0; i < elementos; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            matriz_Id[i][parar] = matriz_Id[i][parar] + ID[i][j];
                            matriz_Im[i][parar] = matriz_Id[i][parar];
                        }
                    }

    cout << "\n\n";

    namedWindow("MALLA", CV_WINDOW_AUTOSIZE);
    imshow("MALLA", img);
    imwrite("Malla.jpg",img);
    waitKey(0);
    destroyWindow("MALLA");
    img.release();
    }
        for(int k = 0; k < vueltas; k++)
        {
            for(int v = 0; v < vueltas - 2; v++)
            {
                suma = 0;
                for(int e = 0; e < elementos; e++)
                {
                    Valores_Jacobianos[e] = (matriz_Id[e][k] * matriz_Im[e][v]);
                    suma = suma + Valores_Jacobianos[e];
                }
                Auxiliar_J[k][v] = suma;
            }
        }

        for(int f = 0; f < D; f++)
        {
            for(int h = 0; h < M; h++)
            {
                contador = contador + 1;
                Guardar_Valor[contador - 1] = Auxiliar_J[f][h];
            }
        }


    for(int n = 0; n < R; n++)
    {
        for(int d = 0; d < elementos; d++)
        {
            Jacobiano[n][d] = (Guardar_Valor[n] * Area[d]);
        }
    }

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    for(int i = 0; i < R; i++)
    {
        cout << "\n";
        for(int g = 0; g < elementos; g++)
        {
            printf("%.2f\t", Jacobiano[i][g]);
        }
    }


    /*cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[9][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[19][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[23][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[33][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[43][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ JACOBIANA *******" << endl;
    cout << "\n";
    cout << "|\t";
    for(int g = 0; g < elementos; g++)
    {
        cout << "\t" << Jacobiano[47][g] << endl;
    }
        printf("   |\t");

    cout << "\n\n";
    cout << "   ******* MATRIZ ID *******" << endl;
    for(int i = 0; i < elementos; i++)
    {
        cout << "\n";
        cout << "|\t";
        for(int g = 0; g < vueltas; g++)
        {
            printf("%.2f\t", matriz_Id[i][g]);
        }
        printf("   |\t");
    }

    cout << "\n\n";
    cout << "   ******* MATRIZ IM *******" << endl;
    for(int i = 0; i < elementos; i++)
    {
        cout << "\n";
        cout << "|\t";
        for(int g = 0; g < vueltas; g++)
        {
            printf("%.2f\t", matriz_Im[i][g]);
        }
        printf("   |\t");
    }*/
    return 0;
}







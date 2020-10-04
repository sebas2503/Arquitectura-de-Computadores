//
//  main.cpp
//  PuntoFlotante
//
//  Created by Luis Sebastian Arroyo Pinto on 10/3/20.
//  Copyright © 2020 Luis Sebastian Arroyo Pinto. All rights reserved.
//

#include <iostream>
#include "cmath"
using namespace std;
float Flotante(float a)
{
    float x = a - int(a);
    return x;
}
double Double(double b)
{
    double y = b - int(b);
    return y;
}
string DecimalBinarioS(int variable)
{
    string v = "";
    while(variable >=1)
    {
        int residuo = variable%2;
        if (residuo == 1)
        {
            v = v+"1";
        }
        else
        {
            v = v+"0";
        }
        variable /= 2;
    }
    int aux = v.size()-1;
    for (int i = 0;i!=v.size()/2;i++)
    {
        int a  = v[i];
        v[i] = v[aux];
        v[aux] = a;
        aux--;
    }
    return v;
}
string FraccionBinarioSF(float a, int numbits)
{
    string almacenador = "";
    for (int i=0;i<numbits;i++)
    {
        a = a*2;
        if (a >= 1)
        {
            almacenador +="1";
            a-=1;
        }
        else
        {
            almacenador +="0";
        }
    }
    return almacenador;
}
string FraccionBinarioSD(double a, int numbits)
{
    string almacenador = "";
    for (int i=0;i<numbits;i++)
    {
        a = a*2;
        if (a >= 1)
        {
            almacenador +="1";
            a-=1;
        }
        else
        {
            almacenador +="0";
        }
    }
    return almacenador;
}
string PFlotanteSF(float x,int exbia, int sig)
{
    string a = DecimalBinarioS(int(x));
    string b = FraccionBinarioSF(Flotante(x),sig);
    string val = a.substr(1,a.size()-1);
    int s = val.size();
    a = a[0];
    string aux = (val+b).substr(0,sig);
    string c = a + "." + aux;
    cout<<c<<" 2^"<<s<<endl;
    return DecimalBinarioS(pow(2,exbia-1)-1+s)+ " "+aux;
}
string PFlotanteSD(double x,int exbia, int sig)
{
    string a = DecimalBinarioS(int(x));
    string b = FraccionBinarioSD(Double(x),sig);
    string val = a.substr(1,a.size()-1);
    int s = val.size();
    a = a[0];
    string aux = (val+b).substr(0,sig);
    string c = a + "." + aux;
    cout<<c<<" 2^"<<s<<endl;
    return DecimalBinarioS(pow(2,exbia-1)-1+s)+ " "+aux;
}
int main(int argc, const char * argv[])
{
    //Flotante
    float numeroF = -6.125;
    string bitsignoF = "";
    int exbiasedF = 8;
    int significandoF = 23;
    //Double
    double numeroD = numeroF;
    string bitsignoD = "";
    int exbiasedD = 11;
    int significandoD = 52;
    //Signo flotante
    if (numeroF>0)
    {
        bitsignoF = "0";
    }
    else
    {
        bitsignoF = "1";
        numeroF *=-1;
    }
    //Signo double
    if (numeroD>0)
    {
        bitsignoD = "0";
    }
    else
    {
        bitsignoD = "1";
        numeroD *=-1;
    }
    string resultado = PFlotanteSF(numeroF,exbiasedF,significandoF);
    string resultado2 = PFlotanteSD(numeroD,exbiasedD,significandoD);
    cout<<bitsignoF<<" "<<resultado<<endl;
    cout<<bitsignoF<<" "<<resultado2<<endl;
    return 0;
}

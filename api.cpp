
#include "api.h"
#include "figures.h"
#include "writefile.h"
#include "randomization.h"


void CreateShapes(const char fileName[], funcParams param)
{
    vector <Point> Points;
    vector <vector <Point>> Figures;
    string str;
    Figure* Cyl = new Cylinder(0, 0);
    Figure* Sph = new Sphere(0);
    Figure* Surface = new Plane(0);
    int check = -1;
    if (fileName[strlen(fileName) - 1] == 'v' &&
        fileName[strlen(fileName) - 2] == 's' &&
        fileName[strlen(fileName) - 3] == 'c')
    {
        check = 0;
    }
    else if (fileName[strlen(fileName) - 1] == 'n' &&
        fileName[strlen(fileName) - 2] == 'o' &&
        fileName[strlen(fileName) - 3] == 's' &&
        fileName[strlen(fileName) - 4] == 'j')
    {
        check = 1;
    }
    switch (param.type)
    {
    case ShapeType::Cylinder:
        for (int i = 0; i < param.count; i++)
        {
            Figure* Cyl = new Cylinder(GetRandIntNumb(10, 100), GetRandIntNumb(10, 100));
            if (param.partition == 0)
            {
                Points = Cyl->GetAsPoints(0);
            }
            else
            {
                Points = Cyl->GetAsPoints(param.partition);
            } 
            Figures.push_back(Points);
            delete Cyl;
        }
        if (check == 0)
        {
            str += Cyl->GetAsCSV(Figures);
        }
        else if (check == 1)
        {
            str += Cyl->GetAsJSON(Figures);
        }
        break;
    case ShapeType::Sphere:
        for (int i = 0; i < param.count; i++)
        {
            Figure* Sph = new Sphere(GetRandIntNumb(10, 100));
            if (param.partition == 0)
            {
                Points = Sph->GetAsPoints(0);
            }
            else
            {
                Points = Sph->GetAsPoints(param.partition);
            }
            Figures.push_back(Points);
            delete Sph;
        }
        if (check == 0)
        {
            str += Sph->GetAsCSV(Figures);
        }
        else if (check == 1)
        {
            str += Sph->GetAsJSON(Figures);
        }
        break;
    case ShapeType::Plane:
        for (int i = 0; i < param.count; i++)
        {
            Figure* Surface = new Plane(GetRandIntNumb(5000, 10000));
            if (param.partition == 0)
            {
                Points = Surface->GetAsPoints(0);
            }
            else
            {
                Points = Surface->GetAsPoints(param.partition);
            }
            Figures.push_back(Points);
            delete Surface;
        }
        if (check == 0)
        {
            str += Surface->GetAsCSV(Figures);
        }
        else if (check == 1)
        {
            str += Surface->GetAsJSON(Figures);
        }
        break;
    }
    WriteFile(fileName, str);
}

// Функция генерации Count фигур рандомного типа
void CreateRandomShapes(const char fileName[], funcParams1 param)
{
    vector <Point> Points;
    vector <vector <Point>> Figures;
    string str;
    int hlp = 0;
    Figure* Cyl = new Cylinder(0, 0);
    Figure* Sph = new Sphere(0);
    Figure* Surface = new Plane(0);
    int check = -1;
    if (fileName[strlen(fileName) - 1] == 'v' &&
        fileName[strlen(fileName) - 2] == 's' &&
        fileName[strlen(fileName) - 3] == 'c')
    {
        check = 0;
    }
    else if (fileName[strlen(fileName) - 1] == 'n' &&
        fileName[strlen(fileName) - 2] == 'o' &&
        fileName[strlen(fileName) - 3] == 's' &&
        fileName[strlen(fileName) - 4] == 'j')
    {
        check = 1;
    }
    for (int i = 0; i < param.count; i++)
    {
        hlp = GetRandIntNumb(1, 3);
        switch (hlp)
        {
        case 1:
            Cyl = new Cylinder(GetRandIntNumb(10, 100), GetRandIntNumb(10, 100));
            if (param.partition == 0)
            {
                Points = Cyl->GetAsPoints(0);
            }
            else
            {
                Points = Cyl->GetAsPoints(param.partition);
            }
            Figures.push_back(Points);
            if (check == 0)
            {
                str += Cyl->GetAsCSV(Points);
            }
            else if (check == 1)
            {
                str += Cyl->GetAsJSON(Figures);
            }
            delete Cyl;
        break;
        case 2:
            Sph = new Sphere(GetRandIntNumb(10, 100));
            if (param.partition == 0)
            {
                Points = Sph->GetAsPoints(0);
            }
            else
            {
                Points = Sph->GetAsPoints(param.partition);
            }
            Figures.push_back(Points);
            if (check == 0)
            {
                str += Sph->GetAsCSV(Points);
            }
            else if (check == 1)
            {
                str += Sph->GetAsJSON(Figures);
            }
            delete Sph;
        break;
        case 3:
            Surface = new Plane(GetRandIntNumb(5000, 10000));
            if (param.partition == 0)
            {
                Points = Surface->GetAsPoints(0);
            }
            else
            {
                Points = Surface->GetAsPoints(param.partition);
            }
            Figures.push_back(Points);
            if (check == 0)
            {
                str += Surface->GetAsCSV(Points);
            }
            else if (check == 1)
            {
                str += Surface->GetAsJSON(Figures);
            }
            delete Surface;
        break;
        }
    }
    WriteFile(fileName, str);
}
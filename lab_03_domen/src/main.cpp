#include <stdio.h>
#include <errno.h>

#include "constants.h"

using namespace std;

#include "builder.h"
#include "loader.h"

#include "objects.h"

#include "matrix.h"
#include "visitor.h"

#include "scene.h"

#include "managers.h"

void manager_scene_test()
{
    double x = 20, y = 30, z = 45;
    shared_ptr<Visitor> visitor_move(new MoveVisitor(x, y, z));

    shared_ptr<Visitor> visitPrint(new DrawVisitor());

    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure1 = loader->loadFigure("figures/simple_figure1.txt");
    shared_ptr<Figure> figure2 = loader->loadFigure("figures/simple_figure2.txt");
    shared_ptr<Figure> figure3 = loader->loadFigure("figures/simple_figure3.txt");

    double nx = 1, ny = 1, nz = 1;
    Point p(0, 0, 0);
    std::shared_ptr<Camera> camera(new Camera(nx, ny, nz, p));
    std::shared_ptr<Camera> camera2(new Camera(nx + 5, ny + 5, nz + 5, p));

    SceneManager sceneManager;

    sceneManager.addComponent(camera);
    sceneManager.addComponent(figure1);

    // sceneManager.addComponent(figure2);
    // sceneManager.addComponent(figure3);
    auto temp = sceneManager.getComponent(TypeObject::FIGURE);
    if (temp) 
    {
        temp->accept(visitPrint);
    }

    temp = sceneManager.getComponent(TypeObject::CAMERA);
    if (temp) 
    {
        temp->accept(visitPrint);
    }


    temp = sceneManager.getComponent(TypeObject::SCENE);
    if (temp) 
    {
        temp->accept(visitor_move);
    }
    std::cout << "________________________________\n\n";
    temp = sceneManager.getComponent(TypeObject::FIGURE);
    if (temp) 
    {
        temp->accept(visitPrint);
    }

    temp = sceneManager.getComponent(TypeObject::CAMERA);
    if (temp) 
    {
        temp->accept(visitPrint);
    }    
}

void scene_test_2()
{
    // Добавляем сцену.
    double x = 20, y = 30, z = 45;
    shared_ptr<Visitor> visitor(new MoveVisitor(x, y, z));

    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure1 = loader->loadFigure("figures/simple_figure1.txt");
    shared_ptr<Figure> figure2 = loader->loadFigure("figures/simple_figure2.txt");
    shared_ptr<Figure> figure3 = loader->loadFigure("figures/simple_figure3.txt");

    double nx = 1, ny = 1, nz = 1;
    Point p(0, 0, 0);
    std::shared_ptr<Camera> camera(new Camera(nx, ny, nz, p));

    Scene scene;

    // figure1->print();
    // figure2->print();
    // camera->print();

    std::cout << "До: " << scene.getCount() << std::endl; 
    scene.addComponent(figure1);
    scene.addComponent(figure2);
    scene.addComponent(camera);
    std::cout << "После: " << scene.getCount() << std::endl; 

    // Это вращение всей сцены.
    std::shared_ptr<Object> composit = scene.getComponent(0);

    IteratorComponent it = composit->begin();
    std::shared_ptr<Object> temp = *it; 

    std::cout << "Это композит: " << temp->isComposite() << "\n";
    std::cout << "Это фигура: " << temp->isVisible() << "\n";

    // while (it != composit->end())
    // {
    //     it++;
    //     std::cout << "Next "; 

    // }
    // std::shared_ptr<Object> obj = *it;
    


}

void scene_test()
{
    // Добавляем сцену.
    double x = 20, y = 30, z = 45;

    shared_ptr<Visitor> visitor(new MoveVisitor(x, y, z));

    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");

    shared_ptr<Figure> figure2 = loader->loadFigure("figures/figure.txt");

    double nx = 5, ny = 6, nz = 7;
    Point p(1, 11, 111);
    std::shared_ptr<Camera> camera(new Camera(nx, ny, nz, p));


    std::shared_ptr<Object> newScene(new Composite());
    newScene->add(figure);
    newScene->add(figure2);
    newScene->add(camera);

    std::cout << "До:\n\n";

    figure->print();
    figure2->print();
    camera->print();

    std::cout << "После:\n\n\n";

    Scene scene;
    scene.addComponent(newScene);
    std::shared_ptr<Object> obj = scene.getComponent(0);
    obj->accept(visitor);

    figure->print();
    figure2->print();
    camera->print();

    std::cout << "Кол-во элементов на сцене: " << scene.getCount() << std::endl; 

    std::shared_ptr<Object> newScene2(new Composite());
    scene.addComponent(newScene2);

    std::cout << "Кол-во элементов на сцене после добавления пустой сцены: " << scene.getCount() << std::endl; 

    ///////
    std::shared_ptr<Camera> camera2(new Camera(nx, ny, nz, p));
    std::shared_ptr<Camera> camera3(new Camera(nx, ny, nz, p));

    scene.addComponent(camera2);
    std::cout << "Кол-во элементов на сцене: " << scene.getCount() << std::endl; 


    scene.addComponent(camera3);
    std::cout << "Кол-во элементов на сцене: " << scene.getCount() << std::endl; 
}

void composit_test_visit()
{
    double _x = 2, _y = 2, _z = 2;
    Matrix<double, 4> moveMatrix = {1, 0, 0, 0,
                                    0, 1, 0, 0,
                                    0, 0, 1, 0,
                                    _x, _y, _z, 1};

    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");

    // figure->print();
    Composite comp;
    comp.add(figure);
    comp.add(figure);
    comp.add(figure);
    comp.transform(moveMatrix);
    // figure->print();
}

void camera_create_and_visit_test()
{
    double nx = 5, ny = 6, nz = 7;
    Point p(1, 11, 111);
    Camera camera(nx, ny, nz, p);
    camera.print();

    double x = 20, y = 11, z = 5;
    shared_ptr<Visitor> visitor(new ScaleVisitor(x, y, z));
    camera.accept(visitor);

    camera.print();
}

void visit_test_figure()
{
    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");
    double x = 20, y = 30, z = 45;

    shared_ptr<Visitor> visitor(new RotateVisitor(x, y, z));
    figure->print();
    figure->accept(visitor);
    figure->print();
}

void composit_test()
{
    double _x = 2, _y = 2, _z = 2;
    Matrix<double, 4> moveMatrix = {1, 0, 0, 0,
                                    0, 1, 0, 0,
                                    0, 0, 1, 0,
                                    _x, _y, _z, 1};

    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");

    figure->print();
    Composite comp;
    comp.add(figure);
    comp.add(figure);
    comp.add(figure);
    comp.transform(moveMatrix);
    figure->print();
}

void addFigure()
{
    //
    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");
    // shared_ptr<Figure> figure = loader->loadFigure("figures/error_file.txt");
    if (figure)
        figure->print();
}

void matrix_test()
{
    double _x = 2, _y = 2, _z = 2;
    Matrix<double, 4> moveMatrix = {1, 0, 0, 0,
                                    0, 1, 0, 0,
                                    0, 0, 1, 0,
                                    _x, _y, _z, 1};

    // std::cout << moveMatrix.at(3, 2);

    MathVector<double, 4> vec = {1, 2, 3, 1};

    vec.multiplication(moveMatrix);

    vec.print();

    double _k = 2;
    Matrix<double, 4> moveScale = {_k, 0, 0, 0,
                                   0, _k, 0, 0,
                                   0, 0, _k, 0,
                                   0, 0, 0, 1};

    vec.multiplication(moveScale);

    vec.print();
}

void transform_test()
{
    shared_ptr<BaseLoader> loaderFile(new FileLoader());
    shared_ptr<Loader> loader(new FigureLoader(loaderFile));
    shared_ptr<Figure> figure = loader->loadFigure("figures/figure1.txt");
    // shared_ptr<Figure> figure = loader->loadFigure("figures/error_file.txt");
    if (!figure)
        return;

    double _k = 2;
    Matrix<double, 4> moveScale = {_k, 0, 0, 0,
                                   0, _k, 0, 0,
                                   0, 0, _k, 0,
                                   0, 0, 0, 1};

    figure->print();
    figure->transform(moveScale);
    figure->print();
}


int main()
{
    setbuf(stdout, NULL);

    cout << endl;
    return OK;
}

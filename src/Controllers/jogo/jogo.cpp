#include "../../../Include/Controllers/jogo/jogo.hpp"
#include <iostream>
#include <memory>
#include <cmath>

Jogo::Jogo() {};

Jogo::~Jogo(){};

int Jogo::setSDLInit() {
    if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
        std::cout << SDL_GetError();
    return 1;
  }
  return 0;
}

void Jogo::setBallsPositions(std::shared_ptr<CenarioJogo> cenarioJogo, std::vector<std::shared_ptr<Bolinha>> &bolinhas) {
    int cont = 0;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 25; j++) {
            if (cenarioJogo->getMap()[i*30][j*30] == 3 || cenarioJogo->getMap()[i*30][j*30] == 6) {
                std::shared_ptr<Textura> textura = bolinhas[cont]->getTextura();
                textura->setTarget(j*30, i*30);
                bolinhas[cont]->setTextura(textura);
                cont++;
            }
        }
    }
}

void Jogo::setInitialPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo) {
    int b = 0;
    for (unsigned long int i = 0; i < cenarioJogo->getHeight(); i++) {
        for (unsigned long int j = 0; j < cenarioJogo->getWidth(); j++) {
            if ((personagem->getGhost() == false && cenarioJogo->getMap()[i][j] == 4) || (personagem->getGhost() == true && cenarioJogo->getMap()[i][j] == 5)) {
                std::shared_ptr<Textura> textura = personagem->getTextura();
                textura->setTarget(j, i);
                personagem->setTextura(textura);
                b = 1;
                break;
            }
        }
        if (b == 1) break;
    }
}

int Jogo::setCharacterPosition(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int x, int y, int oldX, int oldY){
    int **mapa = cenarioJogo->getMap();
    if (personagem->getGhost() == false) {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+y][tx+x] == 3 || mapa[ty+y][tx+x] == 4 || mapa[ty+y][tx+x] == 6) && (mapa[ty+personagem->getHeight()-1+y][tx+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+x] == 4 || mapa[ty+personagem->getHeight()-1+y][tx+x] == 6) && (mapa[ty+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+y][tx+personagem->getWidth()-1+x] == 4 || mapa[ty+y][tx+personagem->getWidth()-1+x] == 6) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 3 || mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 4 || mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] == 6)) {
                textura->setTarget(tx+x, ty+y);
                personagem->setTextura(textura);    
                return 0;
            }
            else if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4 || mapa[ty+oldY][tx+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura); 
                return 1;
            }
        }
        else  {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+oldY][tx+oldX] == 3 || mapa[ty+oldY][tx+oldX] == 4 || mapa[ty+oldY][tx+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] == 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] == 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 3 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 4 || mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] == 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura);    
                return 1;
            }
            return 0;
        }
    }
    else {
        if ((x != 0 || y != 0) && (x != oldX || y != oldY)) {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+y][tx+x] >= 2 && mapa[ty+y][tx+x] <= 6) && (mapa[ty+personagem->getHeight()-1+y][tx+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+x] <= 6) && (mapa[ty+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+y][tx+personagem->getWidth()-1+x] <= 6) && (mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] >= 2 && mapa[ty+personagem->getHeight()-1+y][tx+personagem->getWidth()-1+x] <= 6)) {
                textura->setTarget(tx+x, ty+y);
                personagem->setTextura(textura);    
                return 0;
            }
            else if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura); 
                return 1;
            }
        }
        else  {
            std::shared_ptr<Textura> textura = personagem->getTextura();
            int tx = textura->getTarget().x;
            int ty = textura->getTarget().y;
            if ((mapa[ty+oldY][tx+oldX] >= 2 && mapa[ty+oldY][tx+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+oldX] <= 6) && (mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+oldY][tx+personagem->getWidth()-1+oldX] <= 6) && (mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] >= 2 && mapa[ty+personagem->getHeight()-1+oldY][tx+personagem->getWidth()-1+oldX] <= 6)) {
                textura->setTarget(tx+oldX, ty+oldY);
                personagem->setTextura(textura);    
                return 1;
            }
            return 0;
        }
    }
}

int Jogo::localCharacterControl(std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Teclado> teclado, std::shared_ptr<int> x, std::shared_ptr<int> y, std::shared_ptr<int> cont) { 
    int newX = 0;
    int newY = 0;
    
    teclado->updateState();
    if ((teclado->getState())[SDL_SCANCODE_UP]) {
        newX = 0; 
        newY = -2;
    }
    else if ((teclado->getState())[SDL_SCANCODE_DOWN]) {
        newX = 0; 
        newY = 2;
    }
    else if ((teclado->getState())[SDL_SCANCODE_RIGHT]) {
        newX = 2; 
        newY = 0;
    }
    else if ((teclado->getState())[SDL_SCANCODE_LEFT]) {
        newX = -2; 
        newY = 0;
    }
    int i = setCharacterPosition(personagem, cenarioJogo, newX, newY, (*x), (*y));
    if (i == 0) {
        (*x) = newX;
        (*y) = newY;
    }
    int xpse = personagem->getTextura()->getTarget().x;
    int ypse = personagem->getTextura()->getTarget().y;
    int xpid = personagem->getTextura()->getTarget().x+29;
    int ypid = personagem->getTextura()->getTarget().y+29;
    for (int i = 0; i < bolinhas.size(); i++) {
        int xbse = bolinhas[i]->getTextura()->getTarget().x;
        int ybse = bolinhas[i]->getTextura()->getTarget().y;
        int xbid = bolinhas[i]->getTextura()->getTarget().x+29;
        int ybid = bolinhas[i]->getTextura()->getTarget().y+29;
        if ((xbse == xpse && ((ypse <= ybid-10 && ypse >= ybse+10) || (ypid <= ybid-10 && ypid >= ybse+10))) || (ybse == ypse && ((xpse <= xbid-10 && xpse >= xbse+10) || (xpid <= xbid-10 && xpid >= xbse+10)))) {
            if (bolinhas[i]->getDisplay() == true) {
                bolinhas[i]->setDisplay();
                personagem->setScore(personagem->getScore()+bolinhas[i]->getScore());
                if (bolinhas[i]->getPower() == true && personagem->getPower() == false) {
                    personagem->setPower();
                }
                if (bolinhas[i]->getPower() == false) (*cont)++;
            }
        }
    }

    for (int i = 0; i < inimigos.size(); i++) {
        int xise = inimigos[i]->getTextura()->getTarget().x;
        int yise = inimigos[i]->getTextura()->getTarget().y;
        int xiid = inimigos[i]->getTextura()->getTarget().x+29;
        int yiid = inimigos[i]->getTextura()->getTarget().y+29;


        if (((xpse <= xise && xpid >= xise) || (xpse <= xiid && xpid >= xiid)) && ((ypse <= yise && ypid >= yise) || (ypse <= yiid && ypid >= yiid))) {
            if (inimigos[i]->getLife() >= 0) {
                if (personagem->getPower() == true && personagem->getGhost() == false && inimigos[i]->getGhost() == true) {
                    inimigos[i]->setLife(inimigos[i]->getLife()-1);
                    personagem->setScore(personagem->getScore()+(100*(i+1)));
                    return 0;
                }
                return 1;
            }
        }
    }
    std::cout << "Score: "<< personagem->getScore() <<" ----------------- Extra Life: "<< personagem->getLife() <<"/2 ----------------- Power: " << personagem->getPower() << "\n" <<std::endl;
    if ((*cont) == bolinhas.size()-4) return 2;
    return 0;
}

void Jogo::localNpcControl(std::shared_ptr<Personagem> personagem, std::shared_ptr<CenarioJogo> cenarioJogo, int *x, int *y, int i) { 
    int random0 = rand() % 100;
    int random1 = rand() % 2;
    int random2 = rand() % 2;
    int newX = 0;
    int newY = 0;
    std::shared_ptr<Textura> textura = personagem->getTextura();
    int tx = textura->getTarget().x;
    int ty = textura->getTarget().y;
    if (random0 == 0 || (x[i] == 0 && y[i] == 0)) {
        if (random1 == 0 && random2 == 0) {
            newX = -2;
            newY = 0;
        }
        else if (random1 == 0 && random2 == 1) {
            newX = 2;
            newY = 0;
        }
        else if (random1 == 1 && random2 == 0 && (cenarioJogo->getMap()[ty-1][tx] == 2 || cenarioJogo->getMap()[ty+30][tx] == 2 || cenarioJogo->getMap()[ty][tx] != 5)) {
            newX = 0;
            newY = -2;
        }
        else if (random1 == 1 && random2 == 1 && cenarioJogo->getMap()[ty][tx] != 2 && cenarioJogo->getMap()[ty+29][tx] != 2 && cenarioJogo->getMap()[ty+30][tx] != 2 && cenarioJogo->getMap()[ty][tx] != 5) {
            newX = 0;
            newY = 2;
        }
    }
    int j = setCharacterPosition(personagem, cenarioJogo, newX, newY, x[i], y[i]);
    if (j == 0) {
        x[i] = newX;
        y[i] = newY;
    }
}

void Jogo::iniciarJogo(std::shared_ptr<CenarioJogo> cenarioJogo, std::shared_ptr<Personagem> personagem, std::vector<std::shared_ptr<Personagem>> &inimigos, std::vector<std::shared_ptr<Bolinha>> &bolinhas, std::shared_ptr<View> view, std::shared_ptr<Teclado> teclado, int multi) {
    int state = 0;

    SDL_Event event;

    setBallsPositions(cenarioJogo, bolinhas);

    setInitialPosition(personagem, cenarioJogo);
    
    bool rodando = true;

    char const *img3 = "./assets/pacwpp.jpg";

    std::shared_ptr<Textura> textura3 (new Textura(view->getRenderer(), img3, 0, 0)); // textura 2 (fundo)

    char const *img4 = "./assets/pacwpp2.jpg";

    std::shared_ptr<Textura> textura4 (new Textura(view->getRenderer(), img4, 0, 0)); // textura 2 (fundo)

    char const *img5 = "./assets/pacwpp3.jpg";

    std::shared_ptr<Textura> textura5 (new Textura(view->getRenderer(), img5, 0, 0)); // textura 2 (fundo)

    std::shared_ptr<int> cont (new int);
    (*cont) = 0;

    std::shared_ptr<int> x (new int);
    std::shared_ptr<int> y (new int);
    (*x) = 0;
    (*y) = 0;
    std::shared_ptr<int> x1 (new int);
    std::shared_ptr<int> y1 (new int);
    int *ix = (int*)malloc(inimigos.size()*sizeof(int));
    int *iy = (int*)malloc(inimigos.size()*sizeof(int));
    for (int i = 0; i < inimigos.size(); i++) {
        ix[i] = 0;
        iy[i] = 0;
        setInitialPosition(inimigos[i], cenarioJogo);
    }
    while(rodando) {
        if (state == 0) {
            teclado->updateState();
            if ((teclado->getState())[SDL_SCANCODE_RETURN]) {
                state = 1;
            }
            else if ((teclado->getState())[SDL_SCANCODE_SPACE]) {

                std::ifstream arquivo;
                std::stringstream s;
                arquivo.open("save.txt");
                if (arquivo.is_open() ) {
                    s << arquivo.rdbuf();
                    auto j3 = json::parse(s.str());
                    
                    personagem->setLife(j3["personagem"]["life"].get<int>());
                    personagem->setScore(j3["personagem"]["score"].get<int>());
                    if (j3["personagem"]["power"].get<bool>() == 1) personagem->setPower();
                    personagem->getTextura()->setTarget(j3["personagem"]["x"].get<int>(), j3["personagem"]["y"].get<int>());

                    std::vector<json> in = j3["inimigos"].get<std::vector<json>>();
                    for (int i = 0; i < inimigos.size(); i++) {
                        inimigos[i]->setLife(in[i]["life"].get<int>());
                        inimigos[i]->getTextura()->setTarget(in[i]["x"].get<int>(), in[i]["y"].get<int>());
                    }

                    std::vector<json> pt = j3["bolinhas"].get<std::vector<json>>();
                    for (int i = 0; i < bolinhas.size(); i++) {
                        if (pt[i]["display"].get<bool>() == false) {
                            bolinhas[i]->setDisplay();
                            if (pt[i]["power"].get<bool>() == false) {
                                (*cont)++;
                            }
                        }
                        bolinhas[i]->setScore(pt[i]["score"].get<unsigned long int>());
                        bolinhas[i]->getTextura()->setTarget(pt[i]["x"].get<int>(), pt[i]["y"].get<int>());
                    }
                    
                    arquivo.close();
                }
                state = 1;
            }
            else if ((teclado->getState())[SDL_SCANCODE_TAB]) {
                state = 4;
            }
            else if ((teclado->getState())[SDL_SCANCODE_ESCAPE]) {
                state = 5;
            }
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    rodando = false;
                }
            }
            view->renderClear();
            view->renderMain(textura3);
            view->renderPresent();
            SDL_Delay(10);

        }
        if (state == 1) {
            int res = localCharacterControl(personagem, inimigos, bolinhas, cenarioJogo, teclado, x, y, cont);
            if (res == 2) state = 2;
            if(personagem->getLife() >= 0 && res == 1) {
                personagem->setLife(personagem->getLife()-1);
                if(personagem->getLife() >= 0) setInitialPosition(personagem, cenarioJogo);
                else {
                    if (multi == 0) {
                        state = 3; 
                    }
                }
            }
            for (int i = 0; i < inimigos.size(); i++) {
                localNpcControl(inimigos[i], cenarioJogo, ix, iy, i);
            }
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    json j;
                    json ps;   

                    //save main character
                    ps["x"] = personagem->getTextura()->getTarget().x;
                    ps["y"] = personagem->getTextura()->getTarget().y;
                    ps["score"] = personagem->getScore();
                    ps["life"] = personagem->getLife();
                    ps["power"] = personagem->getPower();


                    std::vector<json> enemies;
                    //save enemies
                    for (int i = 0; i < inimigos.size(); i++) {
                        json en;
                        en["x"] = inimigos[i]->getTextura()->getTarget().x;
                        en["y"] = inimigos[i]->getTextura()->getTarget().y;
                        en["life"] = inimigos[i]->getLife();
                        enemies.push_back(en);
                    }

                    std::vector<json> points;
                    //save points
                    for (int i = 0; i < bolinhas.size(); i++) {
                        json pts;
                        pts["x"] = bolinhas[i]->getTextura()->getTarget().x;
                        pts["y"] = bolinhas[i]->getTextura()->getTarget().y;
                        pts["display"] = bolinhas[i]->getDisplay();
                        pts["score"] = bolinhas[i]->getScore();
                        pts["power"] = bolinhas[i]->getPower();
                        points.push_back(pts);
                    }

                    std::ofstream arquivo1;
                    arquivo1.open("save.txt");

                    j["personagem"] = ps;
                    j["inimigos"] = enemies;
                    j["bolinhas"] = points;
                    arquivo1 << j << std::endl;
                    arquivo1.close();
                    rodando = false;
                }
            }
            view->renderClear();
            view->renderBackground(cenarioJogo->getTextura());
            for (int i = 0; i < bolinhas.size(); i++) {
                if (bolinhas[i]->getDisplay() == true) view->renderCharacter(bolinhas[i]->getTextura());
            }
            for (int i = 0; i < inimigos.size(); i++) {
                if (inimigos[i]->getLife() >= 0) view->renderCharacter(inimigos[i]->getTextura());
            }
            if (personagem->getLife() >= 0) view->renderCharacter(personagem->getTextura());
            view->renderPresent();

            //save
            SDL_Delay(10);
        }
        if (state == 2) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    rodando = false;
                }
            }
            view->renderClear();
            view->renderMain(textura5);
            view->renderPresent();
            SDL_Delay(10);

        }
        if (state == 3) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    rodando = false;
                }
            }
            view->renderClear();
            view->renderMain(textura4);
            view->renderPresent();
            SDL_Delay(10);

        }
        if (state == 4) {
            std::cout << "SERVER SIDE" << std::endl;
            boost::asio::io_service my_io_service; // Conecta com o SO

            udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                            // conf. da conexao (ip/port)

            udp::socket my_socket(my_io_service,   // io service
                                    local_endpoint); // endpoint

            udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

            char v[120];
            my_socket.receive_from(boost::asio::buffer(v, 120), // Local do buffer
                           remote_endpoint);            // Confs. do Cliente
            std::cout << v << std::endl;


            int res = localCharacterControl(personagem, inimigos, bolinhas, cenarioJogo, teclado, x, y, cont);
            if (res == 2) state = 2;
            if(personagem->getLife() >= 0 && res == 1) {
                personagem->setLife(personagem->getLife()-1);
                if(personagem->getLife() >= 0) setInitialPosition(personagem, cenarioJogo);
                else {
                    if (multi == 0) {
                        state = 3; 
                    }
                }
            }
            for (int i = 0; i < inimigos.size(); i++) {
                localNpcControl(inimigos[i], cenarioJogo, ix, iy, i);
            }

            json j;
            json ps;   

            //save main character
            ps["x"] = personagem->getTextura()->getTarget().x;
            ps["y"] = personagem->getTextura()->getTarget().y;
            ps["score"] = personagem->getScore();
            ps["life"] = personagem->getLife();
            ps["power"] = personagem->getPower();


            std::vector<json> enemies;
            //save enemies
            for (int i = 0; i < inimigos.size(); i++) {
                json en;
                en["x"] = inimigos[i]->getTextura()->getTarget().x;
                en["y"] = inimigos[i]->getTextura()->getTarget().y;
                en["life"] = inimigos[i]->getLife();
                enemies.push_back(en);
            }

            std::vector<json> points;
            //save points
            for (int i = 0; i < bolinhas.size(); i++) {
                json pts;
                pts["x"] = bolinhas[i]->getTextura()->getTarget().x;
                pts["y"] = bolinhas[i]->getTextura()->getTarget().y;
                pts["display"] = bolinhas[i]->getDisplay();
                pts["score"] = bolinhas[i]->getScore();
                pts["power"] = bolinhas[i]->getPower();
                points.push_back(pts);
            }

            j["personagem"] = ps;
            j["inimigos"] = enemies;
            j["bolinhas"] = points;
            
            std::string s = j.dump();
            my_socket.send_to(boost::asio::buffer(s), remote_endpoint);

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    rodando = false;
                }
            }
            view->renderClear();
            view->renderBackground(cenarioJogo->getTextura());
            for (int i = 0; i < bolinhas.size(); i++) {
                if (bolinhas[i]->getDisplay() == true) view->renderCharacter(bolinhas[i]->getTextura());
            }
            for (int i = 0; i < inimigos.size(); i++) {
                if (inimigos[i]->getLife() >= 0) view->renderCharacter(inimigos[i]->getTextura());
            }
            if (personagem->getLife() >= 0) view->renderCharacter(personagem->getTextura());
            view->renderPresent();

            //save
            SDL_Delay(10);
        }

        if (state == 5) {
            std::cout << "CLIENT SIDE" << std::endl;

            boost::asio::io_service io_service;

            udp::endpoint local_endpoint(udp::v4(), 0);
            udp::socket meu_socket(io_service, local_endpoint);

            // Encontrando IP remoto
            boost::asio::ip::address ip_remoto =
                boost::asio::ip::address::from_string("127.0.0.1");

            udp::endpoint remote_endpoint(ip_remoto, 9001);

            std::string s = "local";
            meu_socket.send_to(boost::asio::buffer(s), remote_endpoint);

            char v[100000];
            memset(v, 0, 255);
            meu_socket.receive_from(boost::asio::buffer(v, 100000), remote_endpoint);
            json j3 = json::parse(v);
                    
            personagem->setLife(j3["personagem"]["life"].get<int>());
            personagem->setScore(j3["personagem"]["score"].get<int>());
            if (j3["personagem"]["power"].get<bool>() == 1) personagem->setPower();
            personagem->getTextura()->setTarget(j3["personagem"]["x"].get<int>(), j3["personagem"]["y"].get<int>());

            std::vector<json> in = j3["inimigos"].get<std::vector<json>>();
            for (int i = 0; i < inimigos.size(); i++) {
                inimigos[i]->setLife(in[i]["life"].get<int>());
                inimigos[i]->getTextura()->setTarget(in[i]["x"].get<int>(), in[i]["y"].get<int>());
            }

            std::vector<json> pt = j3["bolinhas"].get<std::vector<json>>();
            for (int i = 0; i < bolinhas.size(); i++) {
                if (pt[i]["display"].get<bool>() == false) {
                    bolinhas[i]->setDisplay();
                    if (pt[i]["power"].get<bool>() == false) {
                        (*cont)++;
                    }
                }
                bolinhas[i]->setScore(pt[i]["score"].get<unsigned long int>());
                bolinhas[i]->getTextura()->setTarget(pt[i]["x"].get<int>(), pt[i]["y"].get<int>());
            }

            view->renderClear();
            view->renderBackground(cenarioJogo->getTextura());
            for (int i = 0; i < bolinhas.size(); i++) {
                if (bolinhas[i]->getDisplay() == true) view->renderCharacter(bolinhas[i]->getTextura());
            }
            for (int i = 0; i < inimigos.size(); i++) {
                if (inimigos[i]->getLife() >= 0) view->renderCharacter(inimigos[i]->getTextura());
            }
            if (personagem->getLife() >= 0) view->renderCharacter(personagem->getTextura());
            view->renderPresent();

            //save
            SDL_Delay(10);
        }
    }
};
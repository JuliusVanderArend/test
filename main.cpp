#include <SFML/Graphics.hpp>
#include <random>

#include "Object.h"
#include "Player.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "testClass.h"
#include "SceneState.h"
#include "Utility.h"
#include "Scene.h"
#include "Interactable.h"
#include "LightOBJ.h"
#include "Door.h"
#include "TextBox.h"
#include "SpriteOBJ.h"
#include "PopUp.h"
#include "NPC.h"
#include "SceneOneController.h"
#include "NoteBox.h"

void filler(Object** objectArr,int size) {
    for (int i = 0; i < size; i++) {
        objectArr[i] = new Filler();
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "LD50!");  
    window.setFramerateLimit(60);

    const int NUM_SCENE_OBJECTS = 128;
    const int NUM_SCENES = 128;

    float frame = 0;
    int activeScene = 0;

    Scene scenes[NUM_SCENES];
    sf::Shader* shaders[32];
    //load stuff
    sf::Shader testShader;
    testShader.loadFromFile("assets\\testFragment.frag", sf::Shader::Fragment);
    shaders[0] = &testShader;

    sf::Shader bgShader;
    bgShader.loadFromFile("assets\\bgShader.frag", sf::Shader::Fragment);
    shaders[1] = &bgShader;

    sf::Font mainFont;
    //sf::Font::setSmooth(false);
    mainFont.loadFromFile("color basic.ttf");


    sf::Texture testNormal;
    testNormal.loadFromFile("assets\\red_bricks_04_nor_gl_1k.jpg");

    sf::Texture flatNormal;
    flatNormal.loadFromFile("assets\\flatNormal.png");
    
    sf::Texture pcTexture;
    pcTexture.loadFromFile("assets\\Old__New_PC.png");
    sf::Texture doorTexure;
    doorTexure.loadFromFile("assets\\Rooms_Door.png");
    sf::Texture l1DoorTexture;
    l1DoorTexture.loadFromFile("assets\\L1_Doors.png");
    sf::Texture l2DoorTexture;
    l2DoorTexture.loadFromFile("assets\\L2_Doors.png");
    sf::Texture l3DoorTexture;
    l3DoorTexture.loadFromFile("assets\\L3_Doors.png ");
    sf::Texture desks;
    desks.loadFromFile("assets\\Old__New_Desk.png");
    sf::Texture notesTexture;
    notesTexture.loadFromFile("assets\\Notes.png");
    sf::Texture paperTexture;
    paperTexture.loadFromFile("assets\\Note_blank.png");
    sf::Sprite paperSprite;
    paperSprite.setTexture(paperTexture);
    sf::Texture manTexture;
    manTexture.loadFromFile("assets\\man.png");
    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets\\Player.png");
    sf::Texture playerNormal;
    playerNormal.loadFromFile("assets\\PlayerNormal.png");
    sf::Texture explosionTex;
    explosionTex.loadFromFile("assets\\explosion.png");
    sf::Texture baseNew;
    baseNew.loadFromFile("assets\\reactor_base_new.png");
    sf::Texture baseOld;
    baseOld.loadFromFile("assets\\reactor_base_old.png");
    sf::Texture rod;
    rod.loadFromFile("assets\\reactor_rod.png");
    sf::Texture graphiteTex;
    graphiteTex.loadFromFile("assets\\Graphite.png");

    //sf::Texture testNormal2;
    //testNormal2.loadFromFile("metal_plate_nor_gl_1k.jpg");

    Renderer renderer(&window,shaders);
    //set up sprites/resources
    Material pcMat(&testShader,pcTexture,flatNormal);
    Sprite pcSpriteOld(pcMat);
    pcSpriteOld.sprite.setTextureRect(sf::IntRect(0,15,20,15));
    Sprite pcSpriteNew(pcMat);
    pcSpriteNew.sprite.setTextureRect(sf::IntRect(0, 0, 20, 15));
    Material doorMat(&testShader, doorTexure, flatNormal);
    Sprite doorSprite(doorMat);
    Sprite doorSpriteFliped(doorMat);
    doorSpriteFliped.sprite.setScale(-1, 1);
    Material doorMatl1(&bgShader, l1DoorTexture, flatNormal);
    Sprite l1DoorSprite(doorMatl1);
    Sprite l1DoorSpriteNoInteract(doorMatl1);
    l1DoorSpriteNoInteract.sprite.setTextureRect(sf::IntRect(0, 0, 18, 30));
    Material doorMatl2(&bgShader, l2DoorTexture, flatNormal);
    Sprite l2DoorSprite(doorMatl2);
    Material manMat(&testShader, manTexture, playerNormal);
    Sprite manSprite(manMat);
    Material noteMat(&testShader, notesTexture, flatNormal);
    Sprite noteSprite(noteMat);
    noteSprite.sprite.setTextureRect(sf::IntRect(0, 0, 10, 10));
    Material graphiteMat(&testShader, graphiteTex, flatNormal);
    Sprite graphiteSprite(graphiteMat);
    graphiteSprite.sprite.setTextureRect(sf::IntRect(0, 0, 20, 15));
    Material baseNewMat(&testShader, baseNew, flatNormal);
    Sprite baseNewSprite(baseNewMat);

    Material deskMat(&testShader, desks, flatNormal);
    Sprite oldDesk(deskMat);
    Sprite newDesk(deskMat);
    oldDesk.sprite.setTextureRect(sf::IntRect(37, 0, 37, 12));
    newDesk.sprite.setTextureRect(sf::IntRect(0, 0, 37, 12));

    //scene backgrounds
    sf::Texture s0BG;
    s0BG.loadFromFile("assets\\Ground_Floor_room_3.png");
    sf::Sprite s0BGsprite(s0BG);
    sf::Texture s0BGold;
    s0BGold.loadFromFile("assets\\Ground_Floor_Room_old_day.png");
    sf::Sprite s0BGoldsprite(s0BGold);
    sf::Texture s0BGnew;
    s0BGnew.loadFromFile("assets\\Ground_Floor_Room_present_day.png");
    sf::Sprite s0BGnewsprite(s0BGnew);
    sf::Texture outsideBG;
    outsideBG.loadFromFile("assets\\Ground_Floor_Outside.png");
    sf::Sprite outsideBGSprite(outsideBG);
    sf::Texture officeoldTexture;
    officeoldTexture.loadFromFile("assets\\Dyatlovs_office_old.png");
    sf::Texture officenewTexture;
    officenewTexture.loadFromFile("assets\\Dyatlovs_office_new.png");
    sf::Sprite officeOldSprite(officeoldTexture);
    sf::Sprite officeNewSprite(officenewTexture);
    sf::Texture controlRoomTex;
    controlRoomTex.loadFromFile("assets\\Control_Room.png");
    sf::Sprite controllRoomBG(controlRoomTex);
    
    // set up persistant stuff
    // set up player
    Material playerMat(&testShader, playerTexture, playerNormal);
    Sprite playerSprite(playerMat);
    Player* player = new Player(playerSprite, &renderer);
    player->renderer = &renderer;

    //set up scenes
    //s0
    Scene s0(&renderer,0,"testscene0");
    filler(s0.objects, NUM_SCENE_OBJECTS);
    s0.background = s0BGnewsprite;
    
    TextBox* s0t0 = new TextBox(&window,3,&activeScene,&renderer,player);
    s0t0->text = "hello world this is some test text.hello world this is some test text.hello world this is some test text.";
    s0.objects[6] = s0t0;
    Computer* s0pc0 = new Computer(sf::Vector2f(10,52),20,20,&window,&renderer,player,pcSpriteNew, s0t0);
    s0.objects[0] = s0pc0;
    Computer* s0pc1 = new Computer(sf::Vector2f(70, 52),20, 20, &window, &renderer, player, pcSpriteNew, s0t0);
    s0.objects[1] = s0pc1;
    LightOBJ* s0l0 = new LightOBJ(Light(sf::Vector2f(10, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000),&renderer);
    s0.objects[2] = s0l0;
    LightOBJ* s0l1 = new LightOBJ(Light(sf::Vector2f(80, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000), &renderer);
    s0.objects[3] = s0l1;
    LightOBJ* s0l2 = new LightOBJ(Light(sf::Vector2f(150, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000), &renderer);
    s0.objects[4] = s0l2;
    Door* s0d0 = new Door(sf::Vector2f(156, 49), doorSprite,&renderer,player,&activeScene,2);
    s0.objects[5] = s0d0;
    Door* s0d1 = new Door(sf::Vector2f(4, 49), doorSprite, &renderer, player, &activeScene, 0);
    s0.objects[7] = s0d1;
    SpriteOBJ* s0s0 = new SpriteOBJ(sf::Vector2f(60, 67), newDesk, &renderer);
    s0.objects[8] = s0s0;
    SpriteOBJ* s0s1 = new SpriteOBJ(sf::Vector2f(10, 67), newDesk, &renderer);
    s0.objects[9] = s0s1;
    Door* s0d2 = new Door(sf::Vector2f(130,49), l1DoorSprite, &renderer, player, &activeScene, 4);
    s0.objects[10] = s0d2;

  
    scenes[1] = s0;
    //s1
    Scene s1(&renderer, 1, "testscene1");
    filler(s1.objects, NUM_SCENE_OBJECTS);
    s1.background = outsideBGSprite;
    Door* s1d0 = new Door(sf::Vector2f(156, 50), doorSprite, &renderer, player, &activeScene, 1);
    s1.objects[0] = s1d0;
    LightOBJ* s1l0 = new LightOBJ(Light(sf::Vector2f(300, -60), sf::Vector3f(0.6, 0.7, 0.8), 2000000), &renderer);
    s1.objects[1] = s1l0;
    scenes[0] = s1;

    Scene s2(&renderer, 2, "testscene1");
    filler(s2.objects, NUM_SCENE_OBJECTS);
    s2.background = s0BGsprite;
    Door* s2d0= new Door(sf::Vector2f(4, 50), doorSprite, &renderer, player, &activeScene, 1);
    s2.objects[0] = s2d0;
    SpriteOBJ* s2s0 = new SpriteOBJ(sf::Vector2f(30,67),oldDesk,&renderer);
    s2.objects[1] = s2s0;
    SpriteOBJ* s2s1 = new SpriteOBJ(sf::Vector2f(100, 67), newDesk, &renderer);
    s2.objects[2] = s2s1;
    LightOBJ* s2l0 = new LightOBJ(Light(sf::Vector2f(80, 1), sf::Vector3f(1.0, 1.0, 1.0), 200000), &renderer);
    s2.objects[3] = s2l0;

    scenes[2] = s2;

    Scene s0old(&renderer, 3, "testscene0");
    filler(s0old.objects, NUM_SCENE_OBJECTS);
    s0old.background = s0BGoldsprite;

    TextBox* s0t0old = new TextBox(&window,-1,&activeScene,&renderer, player);
    s0t0old->text = "hello world this is some test text.hello world this is some test text.hello world this is some test text.";
    s0old.objects[6] = s0t0old;
    Computer* s0pc0old = new Computer(sf::Vector2f(10, 52), 20, 20, &window, &renderer, player, pcSpriteOld, s0t0old);
    s0old.objects[0] = s0pc0old;
    Computer* s0pc1old = new Computer(sf::Vector2f(70, 52), 20, 20, &window, &renderer, player, pcSpriteOld, s0t0old);
    s0old.objects[1] = s0pc1old;
    LightOBJ* s0l0old = new LightOBJ(Light(sf::Vector2f(10, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000), &renderer);
    s0old.objects[2] = s0l0old;
    LightOBJ* s0l1old = new LightOBJ(Light(sf::Vector2f(80, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000), &renderer);
    s0old.objects[3] = s0l1old;
    LightOBJ* s0l2old = new LightOBJ(Light(sf::Vector2f(150, 1), sf::Vector3f(1.0, 0.8, 0.7), 80000), &renderer);
    s0old.objects[4] = s0l2old;
    SpriteOBJ* s0d0old = new SpriteOBJ(sf::Vector2f(156, 49), doorSprite, &renderer);
    s0old.objects[5] = s0d0old;
    SpriteOBJ* s0d1old = new SpriteOBJ(sf::Vector2f(4, 49), doorSpriteFliped, &renderer);
    s0old.objects[7] = s0d1old;
    SpriteOBJ* s0s0old = new SpriteOBJ(sf::Vector2f(60, 67), oldDesk, &renderer);
    s0old.objects[8] = s0s0old;
    SpriteOBJ* s0s1old = new SpriteOBJ(sf::Vector2f(10, 67), oldDesk, &renderer);
    s0old.objects[9] = s0s1old;
    SpriteOBJ* s0d2old = new SpriteOBJ(sf::Vector2f(130, 49), l1DoorSpriteNoInteract, &renderer);
    s0old.objects[10] = s0d2old;
    PopUp* s0p00ld = new PopUp("CHERNOBYL - 25TH APRIL 1986 - 8PM", 60, &window);
    s0old.objects[11] = s0p00ld;
    std::string s0oldnpc0lines[5] = { "HAVE YOU READ THE \nBULLITEN YET?", "...YEAH IT'S ABOUT \nTHE TEST", "AT LEAST US NIGHTSHIFT\nLADS WON'T NEED TO BE\n HERE FOR IT, SAYS IT'S\nSTARTING AROUND MIDDAY.","WELL, I'M BACK TO THE\nCONTROLROOM SOON, SAFE\nJOURNEY\ HOME COMERADE.","YOU KNOW YOU DON'T LIVE\nHERE RIGHT? GO SEE THE\nWIFE."};
    int s0oldlineTimes[5] = { 200,300,600,1000,3000 };
    NPC* s0npc0old = new NPC(sf::Vector2f(30, 54), s0oldnpc0lines, s0oldlineTimes,5 , &renderer,&window, manSprite);
    s0old.objects[12] = s0npc0old;
    SceneOneController* s0oldcontroller = new SceneOneController(player, &renderer, &activeScene, 1);
    s0old.objects[13] = s0oldcontroller;
    NoteBox* s0nb0old = new NoteBox(&window, -1, &activeScene, &renderer, player, paperSprite);
    s0nb0old->text = "25th April 1986\n Reactor test to be performed.";
    s0old.objects[14] = s0nb0old;
    Computer* s0n0old = new Computer(sf::Vector2f(104, 37), 10, 10, &window, &renderer, player, noteSprite, s0nb0old);
    s0old.objects[15] = s0n0old;
    scenes[3] = s0old;

    Scene s3(&renderer, 4, "Dyatlov office new");
    filler(s3.objects, NUM_SCENE_OBJECTS);
    s3.background = officeNewSprite;

    NoteBox* s3oldnb0 = new NoteBox(&window, 5, &activeScene, &renderer, player, paperSprite);
    s3oldnb0->text = "They knew...";
    s3.objects[0] = s3oldnb0;
    Computer* s3oldn0 = new Computer(sf::Vector2f(104, 37), 10, 10, &window, &renderer, player, noteSprite, s3oldnb0);
    s3.objects[1] = s3oldn0;
    Door* s3d0 = new Door(sf::Vector2f(156, 49), doorSprite, &renderer, player, &activeScene, 6);
    s3.objects[2] = s3d0;

    scenes[4] = s3;

    Scene s3old(&renderer, 5, "Dyatlov office old");
    filler(s3old.objects, NUM_SCENE_OBJECTS);
    s3old.background = officeOldSprite; 
    PopUp* s3oldp0 = new PopUp("DYATLOV'S OFFICE - 26TH APRIL 1986 - 2 AM", 60, &window);
    s3old.objects[0] = s3oldp0;
    LightOBJ* s30ldl0 = new LightOBJ(Light(sf::Vector2f(35, 10), sf::Vector3f(1.0, 0.9, 0.9), 100000), &renderer);
    s3old.objects[1] = s30ldl0;
    LightOBJ* s30ldl1 = new LightOBJ(Light(sf::Vector2f(155, 40), sf::Vector3f(1.0, 0.2, 0.2), 20000), &renderer);
    s3old.objects[2] = s30ldl1;
    SpriteOBJ* s3d0old = new SpriteOBJ(sf::Vector2f(156, 49), doorSprite, &renderer);
    s3old.objects[3] = s0d0old;

    scenes[5] = s3old;

    Scene s4(&renderer, 6, "controll room");
    filler(s4.objects, NUM_SCENE_OBJECTS);
    s4.background = controllRoomBG;
    Door* s4d0 = new Door(sf::Vector2f(4, 49),doorSprite,&renderer,player,&activeScene,4);
    s4.objects[0] = s4d0;
    Door* s4d1 = new Door(sf::Vector2f(67, 49), l2DoorSprite, &renderer, player, &activeScene, 7);
    s4.objects[1] = s4d1;
    scenes[6] = s4;

    Scene s5(&renderer, 7, "core");
    filler(s5.objects, NUM_SCENE_OBJECTS);
    s5.background = s0BGsprite;

    SpriteOBJ* newbase = new SpriteOBJ(sf::Vector2f(20, 85), baseNewSprite, &renderer);
    s5.objects[0] = newbase;
    LightOBJ* s5l0 = new LightOBJ(Light(sf::Vector2f(80, -90), sf::Vector3f(0.8, 0.8, 1.0), 1000000), &renderer);
    s5.objects[1] = s5l0;
    NoteBox* s5n0 = new NoteBox(&window,8,&activeScene,&renderer,player, paperSprite);
    s5n0->text = "A peice of grapite... I wonder where this came from?";
    s5.objects[2] = s5l0;
    Computer* s5c0 = new Computer(sf::Vector2f(60, 60), 20, 15, &window, &renderer, player, graphiteSprite, s5n0);
    s5.objects[3] = s5c0;

    scenes[7] = s5;

    Scene s5old(&renderer, 8, "core_old");
    filler(s5old.objects, NUM_SCENE_OBJECTS);
    s5old.background = s0BGsprite;

    scenes[8] = s5;
 



    //sf::Shader shaders[128];

    //sf::Shader testShader2;
    //testShader2.loadFromFile("testFragment.frag", sf::Shader::Fragment);


    //Material testMaterial(&testShader,texture,testNormal);
    //Material testMaterial2(&testShader,texture2,testNormal2);

    //Sprite testSprite(testMaterial);
    //testSprite.sprite.setScale(100, 100);
    //Sprite testSprite2(testMaterial2);
    //testSprite2.sprite.setScale(10, 10);
    //testSprite.sprite.setPosition(-400, -1000);
    //testSprite2.sprite.setPosition(200, 200);


    //for (int i = 1; i < 127; i++) {
    //    Particle* particle = new Particle(sf::Vector2f(rand()%1000, rand() % 1000));
    //    particle->renderer = &renderer;
    //    particle->objects = objects;
    //    objects[i] = particle;
    //}

    sf::FloatRect area(0, 0, 160, 90);
    while (window.isOpen())
    {
  
        window.setView(sf::View(area));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update stuff
        sf::Vector2i localPosition = sf::Mouse::getPosition(window); 
        sf::Vector2f pos(localPosition.x, localPosition.y);

        window.clear();
        //persistent updates
        player->update(&scenes[activeScene]);
        //scenes update
        window.draw(scenes[activeScene].background,&bgShader);
        scenes[activeScene].update();
        //for (int i = 0; i < 128; i++) {
        //    std::cout << scenes[activeScene].objects[i]->tag << std::endl;
        //}
        //persistent draws
        player->draw();

        //renderer.addLight(Light(pos, sf::Vector3f(1.0, 0.8, 0.7), 1000));
        //renderer.addLight(Light(sf::Vector2f(100,10), sf::Vector3f(1.0, 0.8, 0.7), 20000));
        //renderer.addLight(Light(sf::Vector2f(800, 10), sf::Vector3f(1.0, 0.8, 0.7), 20000));
        //renderer.addLight(Light(sf::Vector2f(1500, 10), sf::Vector3f(1.0, 0.8, 0.7), 20000));
        //draw stuff
        renderer.setupFrame();
        renderer.afterDraw();
        window.display();
        frame++;
    }
    return 0;
}
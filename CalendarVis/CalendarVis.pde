Mover m;
Mover m1;
Mover m2;
Mover m3;
void setup(){
  size(500,500);
  background(255);
  m = new Mover(width/5,400);
    m1 = new Mover(2*width/5,300);
      m2 = new Mover(3*width/5,200);
        m3 = new Mover(4*width/5,100);
}

void draw(){
  background(0);
  PVector gravity = new PVector(0,0.1);
  m.applyForce(gravity);
  m1.applyForce(gravity);  
  m2.applyForce(gravity);  

  m3.applyForce(gravity);
//  PVector wind = new PVector(3,0);
//  wind.mult(.1);
//    m.applyForce(wind);
  
    m.update();
  m.display();
  m.checkEdges();
  m1.update();
  m1.display();
  m1.checkEdges();
  m2.update();
  m2.display();
  m2.checkEdges();m3.update();
  m3.display();
  m3.checkEdges();
}


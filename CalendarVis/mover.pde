class Mover{
//  float x,y;
//  float vx,vy;
  PVector loc;
  PVector vel;
  PVector accel;
  float mass = 3;
  color col;
  Mover(int x ,int y){
//    x = width/2;
//    y = height/2;;
//    vx=1;
//    vy=0;
    loc = new PVector(x,y);
    vel = new PVector(0,0);
//    vel= PVector.fromAngle(radians(-31));
    accel =  new PVector(0,0);
    col = color(random(127,255),random(127,255),random(127,255));
  }
  //Newtons 2nd law
  void applyForce(PVector force){
    accel.add(force);
  }
 //intergration method
  void update(){
//    x +=vx;
//    y +=vy;
    vel.add(accel);
    loc.add(vel);
    accel.mult(0);
  }
  
  void display(){
    fill(col);
    ellipse(loc.x,loc.y,48,48);
  }
  void checkEdges() {
    float bounce = 1.0;
    if (loc.x > width) {
      loc.x = width;
      vel.x *= -bounce;
    } else if (loc.x < 0) {
      vel.x *= -bounce;
      loc.x = 0;
    }

    if (loc.y > height) {
      vel.y *= -bounce;
      loc.y = height;
    }

  }
  
}
  

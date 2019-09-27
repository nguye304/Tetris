//This program just runs the test grid to show what are the coordinate points

#include <iostream>


const int row = 23;
const int column = 10;

void testGameGrid();
void setUpGameGrid();
void createTetrisShapes(char grid[row][column]);


class ShapeBlock{
public:
  int positionY; 
  int positionX;
  ShapeBlock();
  ~ShapeBlock();
  void changePosition(int x,int y);
  void setPositions(int x, int y);

};

ShapeBlock::ShapeBlock(){
  positionY = column/2;
  positionX = 0;
}
ShapeBlock::~ShapeBlock(){}

void ShapeBlock::setPositions(int x, int y){
  positionY = y;
  positionX = x;

}


class TetrisShape{
public:
  ShapeBlock ShapeArr[4];//array of 4 blocks
  
  TetrisShape();
  ~TetrisShape();
  int getCoordinateY(int);
  int getCoordinateX(int);
  void create();
  void moveDownByOne();
  bool checkValidTetrisShape(ShapeBlock[]);
};

TetrisShape::TetrisShape(){}//Constructor
TetrisShape::~TetrisShape(){}

void TetrisShape::create(){//generates a tetris shape
  int xpos = 4;
  int ypos = 0;
  bool valid = false;
 
  srand(time(NULL));
  for(int i = 0 ; i < 4; i ++){//Going to go through the entire shape array
     xpos = 4;
     ypos = 0;

     if(i == 0){
       ShapeArr[i].setPositions(xpos,ypos);
     }
     else{
       do{//do this randon number generation if its not the first block
	xpos = 3+(rand() % 6);//randon number between 3 and 6         
        ypos = rand() % 1;//randon number between 0 and 1                                                     
        //std::cout<<xpos<<" "<<ypos<<"\n";
       }while(xpos==4 && ypos==0);  
       ShapeArr[i].setPositions(xpos,ypos);
     }
    }//for loop end
}

bool TetrisShape::checkValidTetrisShape(ShapeBlock shape[]){
  bool validity = false;
  int temp[4];
  
  //for(int i = 0 ; i <4 ; i++){
    //std::cout<<"\n"<<shape[i].positionY;
    //std::cout<<"\n"<<shape[i].positionX;
    //if (shape[i].positionY==something){
    
    // }

  //}
  
  validity = true;
  return validity;
}


int TetrisShape::getCoordinateY(int num){
  return ShapeArr[num].positionY;
}
int TetrisShape::getCoordinateX(int num){
  return ShapeArr[num].positionX;
}



int main(){
  std::cout<<"Tetris!"<<std::endl;
  //createTetrisShapes();
  //For tetris i will need a grid  
  //Need to have pieces in 4s - Different shapes
  //Pieces need to be moving down 
  //pieces need to be moving faster over time
  //if the pieces fill up an entire row then i need to delete that row
  //Set up the game board  
  // setUpGameGrid();
  testGameGrid();
return 0;
}

void testGameGrid(){
  int gameGrid[row][column];
  for( int y = 0 ; y < row; y++){
    for(int x = 0; x < column ;x++){
      for(int i = 0 ; i <2; i++){
	if (i == 0)
	  std::cout<<x<<",";
	else
	  std::cout<<y<<"      ";
      }
    }
    printf("\n");
  }

}

void setUpGameGrid(){  //Set up the game board                                                                                                                                                         
  char gameGrid[row][column];
  bool valid=false;
  TetrisShape tet;
  do{
    tet.create();
    valid = tet.checkValidTetrisShape(tet.ShapeArr);
  }while(valid==false);
  int i = 0;
  /*for(i = 0; i < 4 ; i ++){
        std::cout<<tet.getCoordinateX(i)<<" " <<tet.getCoordinateY(i)<<std::endl;
	}*/

  for(int y = 0 ; y < row ; y++){
    for(int x = 0 ; x  < column; x++){

	if(y==row-1 || x==0 || x==column-1){
	  gameGrid[y][x]='X';
	}
	else{
	  for(i = 0 ; i < 4 ; i ++){
	    int yTemp=tet.getCoordinateY(i);
	    int xTemp=tet.getCoordinateX(i);
	    //std::cout<<xTemp<<" " <<yTemp<<std::endl;
	    
	    if(x==xTemp && y == yTemp){ gameGrid[y][x]='O';}
	    else if(gameGrid[y][x]=='O'){gameGrid[y][x]=gameGrid[y][x];}
	    else{gameGrid[y][x]=' ';}
	  }
	}
      std::cout<<gameGrid[y][x]<<" ";
    }
    std::cout<<std::endl;
  }
}


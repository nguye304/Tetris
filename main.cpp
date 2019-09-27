//This program is a Tetris game where you can play against an AI

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
  
};

TetrisShape::TetrisShape(){}//Constructor
TetrisShape::~TetrisShape(){}

void TetrisShape::create(){//generates a tetris shape
  int xpos = 4;
  int ypos = 0;
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
      }while(xpos==4 && ypos==0);
      
      ShapeArr[i].setPositions(xpos,ypos);
    }
  }
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
  setUpGameGrid();
  //testGameGrid();
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
  for(int y = 0 ; y < row ; y++){
    for(int x = 0 ; x  < column; x++){
      if(y==row-1 || x==0 || x==column-1){
        gameGrid[y][x]='X';
      }
      else{
        if(x==4 && y == 0){
	  createTetrisShapes(gameGrid);  //pass the grid into the function
	}
	else{
	  gameGrid[y][x]=' ';
	}
      }
      std::cout<<gameGrid[y][x]<<" ";
    }
    std::cout<<std::endl;
  }
}



void createTetrisShapes(char grid[row][column]){
  TetrisShape tet;
  tet.create();
  int x,y;
  for(int i = 0 ; i < 4 ; i++){
    y = tet.getCoordinateY(i);
    x = tet.getCoordinateX(i);
        std::cout<<x<<y<<"\n";
    grid[y][x]= 'O';
  }

}

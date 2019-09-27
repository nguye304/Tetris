//This program is a Tetris game where you can play against an AI

#include <iostream>


const int row = 23;
const int column = 10;

void testGameGrid();
void setUpGameGrid();
void createTetrisShapes();


class ShapeBlock{
public:
  int positionY = column/2; 
  int positionX;
  void changePosition(int x,int y);
  void setPositions(int x, int y);
};

void ShapeBlock::setPositions(int x, int y){
  positionY = y;
  positionX = x;

}




class TetrisShape{
public:
  ShapeBlock ShapeArr[4];//array of 4 blocks
  
  TetrisShape();
  TetrisShape()~;
  void printTetrisShape();
  void moveDownByOne();

};


void TetrisShape::TetrisShape(){//constructor
  //generates a tetris shape
  for(int i = 0 ; i < 4; i ++){
    xpos = 4;
    ypox = 0;

    if(i == 0){
      ShapeArr[i].setPosition(xpos,ypos)
    }
    else{
      do{//do this randon number generation if its not the first block
	xpos = rand() % 6 + 3;//randon number between 3 and 6                                                 
	ypos = rand() % 1;//randon number between 0 and 1                                                     
      }while(xpos==4 && ypos==0);
      
      ShapeArr[i].setPosition(xpos,ypos);
    }
  }
}

void TetrisShape::printTetrisShape(){
  for(int i = 0 ; i < 4; i ++){
    
    std::cout<<'O';
  }
  
  

}


int main(){
  std::cout<<"Tetris!"<<std::endl;
  createTetrisShapes();
  int num = 0;
  while(num != 10){
    num = rand()% 10+1;
    std::cout<<num<<"\n\n";
  }
  //For tetris i will need a grid  
  //Need to have pieces in 4s - Different shapes
  //Pieces need to be moving down 
  //pieces need to be moving faster over time
  //if the pieces fill up an entire row then i need to delete that row
  //Set up the game board  
  //setUpGameGrid();
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
  for(int y = 0 ; y < row ; y++){
    for(int x = 0 ; x  < column; x++){
      if(y==0 || y==row-1 || x==0 || x==column-1){
        gameGrid[y][x]='X';
      }
      else{
        if(x==24){
	  createTetrisShapes();
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



void createTetrisShapes(){
  TetrisShape tet;
  tet.ShapeArr[0].setPositions(1,1);
  std::cout<<tet.ShapeArr[0].positionY<<"\n";
  std::cout<<tet.ShapeArr[0].positionX<<"\n\n";
  
}

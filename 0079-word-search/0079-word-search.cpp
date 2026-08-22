class Solution {
public:
bool fun(vector<vector<char>> &board,string &word,int row,int col,int index){

    if(index == word.size()){
        return true;
    }
//out of bound
    if(row < 0 ||  row >= board.size() || col < 0 || col >= board[0].size()){
        return false;
    }

    if(board[row][col] != word[index]){
        return false;
    }

    char ch = board[row][col];
    board[row][col] = ' ';

    if(fun(board,word,row-1,col,index+1) || //up
    fun(board,word,row+1,col,index+1) ||  //down
    fun(board,word,row,col+1,index+1) ||  // right
    fun(board,word,row,col-1,index+1))  //left
    return true;

    board[row][col] = ch ;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(board[i][j] == word[0]){

                    if(fun(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
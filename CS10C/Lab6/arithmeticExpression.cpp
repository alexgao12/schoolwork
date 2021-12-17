#include "arithmeticExpression.h"


int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
void arithmeticExpression::visualizeTree(ofstream & fs, TreeNode *node){
  if(node->left == nullptr){
    return;
  }
  fs << "key\"" << node->key << "\" -> \"" << node->left->key << "\";" << endl;
  fs << "key\"" << node->key << "\" -> \"" << node->right->key << "\";" << endl;
  visualizeTree(fs, node->left);
  visualizeTree(fs, node->right);
}

void arithmeticExpression::infix(){
  //cout << "(" ;
  infix(root);
  //cout << ")";
}
void arithmeticExpression::infix(TreeNode* p){
  if(p == nullptr){
    return;
  }
  if(p->left != nullptr){
    cout << "(";
  }
  infix(p->left);
  cout << p->data;
  infix(p->right);
  if(p->left != nullptr){
    cout << ")";
  }
}

void arithmeticExpression::prefix(){
  prefix(root);
}
void arithmeticExpression::prefix(TreeNode* p){
  if(p == nullptr){
    return;
  }
  cout << p->data;
  prefix(p->left);
  prefix(p->right);
}

void arithmeticExpression::postfix(){
  postfix(root);
}
void arithmeticExpression::postfix(TreeNode* p){
  if(p == nullptr){
    return;
  }
  postfix(p->left);
  postfix(p->right);
  cout << p->data;
}

arithmeticExpression::arithmeticExpression(const string& s){
  infixExpression = s;
  root = nullptr;
}

void arithmeticExpression::buildTree(){
  char key = 'a';
  stack<TreeNode*> expression;
  string postfixexpression = infix_to_postfix();
  for(char &c : postfixexpression){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
      TreeNode* temp1 = expression.top();
      expression.pop();
      TreeNode* temp2 = expression.top();
      expression.pop();
      TreeNode* t = new TreeNode(c, key);
      ++key;
      t->left = temp2;
      t->right = temp1;
      expression.push(t);
      
    }else{
      expression.push(new TreeNode(c,key));
      ++key;
    }
  }
  root = expression.top();

}



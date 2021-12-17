#include "Graph.h"

Graph::Graph(){
}

Graph::Graph(ifstream& fin){
  Vertex* currVer;
  int nodes, edges, cost, index, findex;
  string temp;
  fin >> nodes >> edges;
  for(int i = 0; i < nodes; ++i){
    fin >> temp;
    Vertex ver = Vertex();
    ver.label = temp;
    vertices.push_back(ver);
  }
  vertices.at(0).distance = 0;
  fin.clear();
  for(int j = 0; j < edges; ++j){
    fin >> temp;
    for(int i = 0; i < vertices.size(); ++i){
      if(vertices.at(i).label == temp){
        currVer = &vertices.at(i);
        findex = i;
      }
    }
    fin >> temp;
    fin >> cost;
    for(int k  = 0; k < vertices.size(); ++k){
      //cout << "test" << endl;
      if(temp == vertices.at(k).label){
        index = k;
      }
    }
    //cout << "test2" << endl;
    pair<int,int> p(index, cost);
    //cout << "test5" << endl;
    //currVer.neighbors.push_back(p);
    vertices.at(findex).neighbors.push_back(p);
    //cout << "test6" << endl;
  }
}

Graph::~Graph(){
  
}

void Graph::bfs(){
  // for(int i = 0; i < vertices.size(); ++i){
  //   cout << vertices.at(i).label << endl;
  //   //cout << (vertices.at(0).label) << endl;
  // }
  //cout << (vertices.at(0).label) << endl;
  queue<Vertex*> todo;
  todo.push(&vertices.at(0));
  //cout << (vertices.at(0).label) << endl;
  while(!todo.empty()){
    Vertex* currVer = todo.front();
    todo.pop();
    //cout << (vertices.at(0).label) << endl;
    //cout << currVer->neighbors.back().first << endl;
    for(auto const& adj : currVer->neighbors){
      //cout << "test" << endl;
      if(vertices.at(adj.first).color == "WHITE"){
        vertices.at(adj.first).color = "GRAY";
        vertices.at(adj.first).distance = currVer->distance + 1;
        vertices.at(adj.first).prev = currVer;
        todo.push(&vertices.at(adj.first));
      }
    }
    currVer->color = "BLACK";
  }
}

void Graph::output_graph(const string& outputFilename){
      // for(auto adj: vertices.at(4).neighbors){
      //   //cout << "does this work" << endl;
      //   cout << vertices.at(adj.first).label << endl;
      // }
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;

    for(int i = 0; i < vertices.size(); ++i){
      //cout << "please work" << endl;
      for(auto adj: vertices.at(i).neighbors){
        //cout << "does this work" << endl;
        cout << vertices.at(i).label << " -> " << vertices.at(adj.first).label << " " << vertices.at(adj.first).distance << endl;
        outFS << vertices.at(i).label << " -> " << vertices.at(adj.first).label << ";" << endl;
      }
    }

    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
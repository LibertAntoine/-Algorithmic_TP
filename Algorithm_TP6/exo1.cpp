#include "lib/tp6.h"
#include <QApplication>
#include <time.h>
#include <cmath>
#include <stdio.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	for(int i = 0; i < nodeCount ; i++) {
		GraphNode* gn;
		gn->value = i;
		this->appendNewNode(gn);
	}
	for(int i = 0; i < nodeCount ; i++) {
		for(int j = 0; j < nodeCount ; j++) {
      if(adjacencies[i][j] == true) {
        this->nodes[i]->appendNewEdge(this->nodes[j]);
      }
    }
	}     
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int& nodesSize, bool visited[])
{
	visited[first->value]=true;
	nodes[nodesSize] = first;
	nodesSize++;
  for(Edge* e = first->edges ; e != NULL; e = e->next) {
    if(!visited[e->destination->value]) {
      this->deepTravel(e->destination, nodes, nodesSize, visited);
		}
	}
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);

	while(!nodeQueue.empty()) {
		GraphNode *v = nodeQueue.front();
		nodeQueue.pop();
    visited[v->value] = true; 
		nodes[nodesSize] = v;
		nodesSize++;

    for(Edge* e = v->edges ; e != NULL; e = e->next) {
      if(!visited[e->destination->value]) {
        nodeQueue.push(e->destination);
			}
		}
	}
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);

	while(!nodeQueue.empty()) {
    GraphNode *v = nodeQueue.front();
    nodeQueue.pop();
    visited[v->value] = true;

    for(Edge* e = v->edges ; e != NULL; e = e->next) {
      if(e->destination->value == first->value) {
				return true;
      } else if(!visited[e->destination->value]) {
        nodeQueue.push(e->destination);
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}

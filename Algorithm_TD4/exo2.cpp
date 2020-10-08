#include "lib/TP4.h"

#include "lib/mainwindow.h"
#include <QApplication>
#include <time.h>
#include <stdio.h>

_TestMainWindow* w = nullptr;
using std::size_t;
using std::string;



void HuffmanHeap::insertHeapNode(int heapSize, char c, int frequences)
{
  int i = heapSize;
  HuffmanNode node;
  node.character = c;
  node.value = frequences;
  this->get(i) = node;

  while((i>0) && (this->get(i).value>this->get(i/2).value)){
    swap(i, i/2);
    i = i/2;
  }
}

void HuffmanNode::insertNode(HuffmanNode* node)
{
  if(this->value <= this->value/3){
    if(this->right == NULL){
      this->right = node;
    } else {
      if(this->right->isLeaf()){
        HuffmanNode* parent = new HuffmanNode();
        parent->right = this->right;
        parent->left = node;
        this->right = parent;
      } else {
          this->right->insertNode(node);
      }
    }
  } else {
    if(this->left == NULL){
      this->left = node;
    } else {
      if(this->left->isLeaf()){
        HuffmanNode* parent = new HuffmanNode();
        parent->left = this->left;
        parent->right = node;
        this->left = parent;
      } else {
        this->left->insertNode(node);
      }
    }
  }
}

void HuffmanNode::processCodes(std::string baseCode){
  if(this->isLeaf()){
    this->code = baseCode;
  } else {
    if(this->left != NULL){
      this->left->processCodes(baseCode+"0");
    }
    if(this->right != NULL){
      this->right->processCodes(baseCode+"1");
    }
  }
}

void charFrequences(string data, Array& frequences){
  for(int i=0; i<data.size(); i++){
    frequences[data[i]]++;
  }
}

void huffmanHeap(Array& frequences, HuffmanHeap& heap)
{
  int heapSize = 0;
  for(int i=0; i<frequences.size() ; i++){
    if(frequences[i] > 0){
      heap.insertHeapNode(heapSize, i, frequences[i]);
      heapSize++;
    }
  }
}

void huffmanDict(HuffmanHeap& heap, HuffmanNode*& dict)
{
	dict = new HuffmanNode('\0', heap[0].value + heap[1].value);
	dict->left = &heap[0];
	dict->right = &heap[1];
  for(int i = 2 ; i<heap.size() ; i++){
    dict->insertNode(&heap[i]);
  }
}

string huffmanEncode(HuffmanNode** characters, string toEncode){
	string encoded= "";
  for(int i=0 ; i<toEncode.size() ; i++){
    encoded += characters[toEncode[i]]->code;
  }

	return encoded;
}

string huffmanDecode(HuffmanNode* dict, string toDecode){
	string decoded= "";
  HuffmanNode* current = dict;

  for(int i=0 ; i<=toDecode.size() ; i++){
    if(current->isLeaf()){
      decoded+=current->character;
      current = dict;
      i--;
    } else {
      if(toDecode[i] =='0'){
        current = current->left;
      } else {
        current = current->right;
      }
    }
  }
  return decoded;
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 30;
	NumberGraphicsItem::baseColor = QColor(240,255,245);
	w = new HeapTestMainWindow();

	string data = "Ouesh, bien ou bien ? Ceci est une chaine de caractere sans grand"
				  " interet";

	Array& frequences = w->newArray(256);
	HuffmanHeap heap(256);
	HuffmanNode* dict;

	for (int i=0; i<frequences.size(); ++i)
		frequences.__set__(i, 0);

	charFrequences(data, frequences);
	huffmanHeap(frequences, heap);
	huffmanDict(heap, dict);
	dict->processCodes("");

	HuffmanNode* characters[256];
	memset(characters, 0, 256 * sizeof (HuffmanNode*));
	dict->fillCharactersArray(characters);

	string encoded = huffmanEncode(characters, data);
	string decoded = huffmanDecode(dict, encoded);

	w->updateScene();
	w->addBinaryNode(dict);
	qDebug("Encoded: %s\n", encoded.c_str());
	qDebug("Decoded: %s\n", decoded.c_str());

	w->show();
	return a.exec();
}



struct Node {
	int data;
	Node* left;
	Node* right;
};

extern Node* RootPBT;

Node* AddNodes(Node* pCurrent, int count);
void deletePBT(Node* pCurrent);
void printInverselySymmetrical(Node* pCurrent, int levelPBT);
void printSymmetrical(Node* pCurrent, int levelPBT);

struct Stack {
	int levelPBT;
	Node* passedVertex; 
	Stack* next; 
};

extern Stack* stack;

void initStack(Node* PBT);


void printForward(Node* pCurrent, int levelPBT);
void printNonRecursiveSymmetrical();
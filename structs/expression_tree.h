#ifndef _S16_EXPRESSION_TREE_H__
#define _S16_EXPRESSION_TREE_H__

#include <string>

class AbstractExpressionTree {
public:
  AbstractExpressionTree(std::string rpn);
  ~AbstractExpressionTree();

  // Evaluate the tree.
  int eval();

  // Ouput a dot file to give to WebGraphViz.com
  void output_dot(std::string filename);

  void PrintPreOrder();
  void PrintInOrder();
  void PrintPostOrder();

private:
  struct Node {
    virtual int eval() = 0;
    virtual void PrintInOrder() = 0;
    virtual void PrintPreOrder() = 0;
    virtual void PrintPostOrder() = 0;
    virtual std::string symbol() = 0;
    virtual ~Node() {}
  };

  Node* root_;

  struct BinaryNode : public Node {
    BinaryNode(Node* l, Node* r) : left(l), right(r) {}
    virtual ~BinaryNode() {
      delete left;
      delete right;
    }
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    Node* left;
    Node* right;
  };

  struct AddNode : public BinaryNode {
    AddNode(Node* l, Node* r);
    std::string symbol() { return "+"; }
    int eval();
  };

  struct SubtractNode : public BinaryNode {
    SubtractNode(Node* l, Node* r);
    std::string symbol() { return "-"; }
    int eval();
  };

  struct MultiplyNode : public BinaryNode {
    MultiplyNode(Node* l, Node* r);
    std::string symbol() { return "*"; }
    int eval();
  };

  struct DivideNode : public BinaryNode {
    DivideNode(Node* l, Node* r);
    std::string symbol() { return "/"; }
    int eval();
  };

  struct ValueNode : public Node {
    ValueNode(int v) : value(v) {}
    std::string symbol() { return ""; }
    int eval();
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    int value;
  };
};

class ExpressionTree {
public:
  ExpressionTree(std::string rpn);
  ~ExpressionTree();

  // Evaluate the tree.
  int eval();

  // Ouput a dot file to give to WebGraphViz.com
  void output_dot(std::string filename);

  void PrintPreOrder();
  void PrintInOrder();
  void PrintPostOrder();

private:
  struct Node {
    enum Operation { Add, Subtract, Multiply, Divide, Value };

    // Binary operation constructor.
    Node(Operation o, Node* l, Node* r) : op(o), left(l), right(r) {}

    // Leaf value constructor.
    Node(int v) : op(Value), value(v), left(nullptr), right(nullptr) {}

    // Destructor which recursively deletes left and right nodes.
    ~Node();

    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();

    int eval();

    Operation op;
    int value;
    Node* left;
    Node* right;
  };

  Node* root_;
};

#endif // _S16_EXPRESSION_TREE_H__
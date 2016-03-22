#include <iostream>
#include <vector>
using namespace std;

struct Tree{
  long val;
  Tree *left;
  Tree *right;
  int depth;
  Tree () {
    val = -1;
  }
};

struct Line_part {
  long val;
  bool isVal;
  Line_part(long a, bool b) {
    val = a;
    isVal = b;
  }
};
void tree_add(Tree *nd, long val, int depth) {
  if (nd->val == -1) {
    nd->val = val;
    nd->left = new Tree();
    nd->right = new Tree();
    nd->depth = depth;
  }
  else if (nd->val > val) {
    tree_add(nd->left, val, nd->depth + 1);
  }
  else {
    tree_add(nd->right, val, nd->depth + 1);
  }
}

struct Line {
  int length;
  vector<Line_part> parts;
  Line() {
    length = 0;
  }
};
vector<Line> rect;
long n = 0;
void tree_print (Tree *nd) {
  if (nd->val == -1)
    return;
  tree_print(nd->left);
  int c = 1;
  long t = nd->val;
  while (t >= 10) {
    t /= 10;
    ++c;
  }
  if (rect.size() <= nd->depth) {
    rect.resize((nd->depth + 1) * 2, Line());
  }
  Line *line = &rect[nd->depth];
  line->parts.push_back(Line_part(n - line->length, false));
  line->parts.push_back(Line_part(nd->val, true));
  line->length += c + n - line->length;
  n += c;
  tree_print(nd->right);
}

int main() {
  long d;
  Tree *root = new Tree();
  while (1) {
    cin >> d;
    tree_add(root, d, 0);
    if (cin.get() != ' ')
      break;
  }
  tree_print(root);
  for (int i = 0; i < rect.size(); ++i) {
    Line *line = &rect[i];
    if (line->length == 0)
      break;
    for (int j = 0; j < line->parts.size(); ++j) {
      if (line->parts[j].isVal) {
        cout << line->parts[j].val;
      }
      else {
        for (int k = 0; k < line->parts[j].val; ++k)
          cout << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

// github 용
#include <iostream>
#include <queue>
using namespace std;
 
class TreeNode {
public:    
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
 
TreeNode* buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;
    
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < size) {
            curr->left = new TreeNode(nums[i++]);
            q.push(curr->left);
        }
        if (i < size) {          
            curr->right = new TreeNode(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
 
void printInOrderTree(TreeNode* root) {
    //만약 없으면 그냥 리턴으로 끝내버림
    if (!root) return;
    //위에서 거르니까 양쪽 다 들어감
    printInOrderTree(root->left);
    //중위여서 중간
    if(root->val != 0){ //없는 값 거르기
        cout << root->val << " ";
    }
    printInOrderTree(root->right);
}
 
int main() {
    // int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size;
    cin>>size;
    int nums[size];
    for(int i=0; i<size; i++){
        cin>>nums[i];
    }

    TreeNode* root = buildTree(nums,size);
    printInOrderTree(root);
    cout<<endl;
    return 0;
}
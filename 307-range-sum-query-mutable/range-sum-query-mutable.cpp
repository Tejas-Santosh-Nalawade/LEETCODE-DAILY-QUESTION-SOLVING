class Node {
    public:
    int start, end, sum;
    Node* left = NULL;
    Node* right = NULL;

    Node(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
    }
};

class NumArray {
public:
    Node* root;

    NumArray(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);    
    }

    Node* build(vector<int>& nums, int left, int right) {
        if(left == right) return new Node(left, right, nums[left]);

        Node* root = new Node(left, right, 0);
        int mid = (left + right) / 2;
        
        root->left = build(nums, left, mid);
        root->right = build(nums, mid + 1, right);
        root->sum = root->left->sum + root->right->sum;

        return root;
    }
    
    void update(int index, int val) {
        update(root, index, val);
    }
    
    void update(Node* root, int index, int val) {
        if(root == NULL) return;
        if(index < root->start || index > root->end) return;

        if(root->start == root->end) {
            root->sum = val;
            return;
        }

        update(root->left, index, val);
        update(root->right, index, val);
        root->sum = root->left->sum + root->right->sum;
    }

    int query(Node* root, int ql, int qr) {
        if(root == NULL) return 0;

        // Case 1: Root Node is completely inside Query
        if(ql <= root->start && qr >= root->end) return root->sum;

        // Case 2: There is No Overlap
        if(qr < root->start || ql > root->end) return 0;

        // Case 3: Query is Completely inside Root / Partial Overlap
        return query(root->left, ql, qr) + query(root->right, ql, qr);
    }

    int sumRange(int left, int right) {
        return query(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
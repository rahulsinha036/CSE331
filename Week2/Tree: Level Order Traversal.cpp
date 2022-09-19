import java.util.*;
import java.io.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {


    static ArrayList<ArrayList<Integer>> l=new ArrayList<ArrayList<Integer>>();
    static{
        for (int i=0;i<200;i++){
            l.add(new ArrayList<Integer>());
        }
    }
    static int curr=0;
    public static void levelOrder(Node root) {
      if(root==null){return;}
      else{
          l.get(curr).add(root.data);
      }
      
      if(root.left!=null){
          curr++;
          levelOrder(root.left);
          curr--;
      }
      if(root.right!=null){
          curr++;
          levelOrder(root.right);
          curr--;
      }
      
    }
    public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
        scan.close();
        levelOrder(root);
        for (int i = 0; i < l.size(); i++) {
            for (int j = 0; j < l.get(i).size(); j++) {
                System.out.print(l.get(i).get(j) + " ");
            }
            
        }
    }    
}

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

   static HashMap<Integer,Integer> level=new HashMap<Integer,Integer>();
   static int level1[]=new int[99999];
   static int current=0;
	 static int vertlvl=0;
    public static void topView(Node root) {
        vertlvl++;
        if(!level.containsKey(current) || level1[level.get(current)]>vertlvl){
				level.put(current, root.data);
				 level1[root.data]=vertlvl;
	  }
       if(root==null){return;}
        if(root.left!=null){
            current-=1;
            topView(root.left);
            current+=1;
            }
        
         if(root.right!=null){
            current+=1;
            topView(root.right);
            current-=1;
            }
      vertlvl--;
      
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
    
    public static void sortbykey()
    {
    
        TreeMap<Integer, Integer> sorted = new TreeMap<>();
 
        sorted.putAll(level);
 
     
        for (Map.Entry<Integer, Integer> entry : sorted.entrySet())
            System.out.print(entry.getValue()+" ");       
    
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
        topView(root);
        sortbykey();
    }    
}

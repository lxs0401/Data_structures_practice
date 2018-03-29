import java.util.*;


class sortTree
{
	final int DELETE = 1;
	int val;
	sortTree lc = null,rc = null;
	int tag = 0;
	public sortTree(){
		tag = DELETE;
	}
	public int search(int[] print,Integer index)
	{
		if(tag == DELETE){
			return index;
		}
		if(lc != null){
			index = lc.search(print,index);
		}
		print[index] = val;
		index += 1;
		if(rc != null){
			index = rc.search(print,index);
		}
		return index;
	}
	public boolean delete(int val)
	{
		if(tag == DELETE){
			return false;
		}
		else if (val == this.val)
		{
			tag = DELETE;
			return true;
		}
		
		if(val < this.val)
		{
			if(lc == null){
				return false;
			}
			return lc.delete(val);
		}
		else
		{
			if(rc == null){
				return false;
			}
			return rc.delete(val);
		}
	}
	public void insert(int val)
	{
		if(tag == DELETE)
		{
			this.val = val;
			tag = 0;
		}
		else 
		{
			if(val < this.val)
			{
				if(lc == null){
					lc = new sortTree();
				}
				lc.insert(val);
			}
			else
			{
				if(rc == null){
					rc = new sortTree();
				}
				rc.insert(val);
			}
		}
	}
}
public class Main
{
	public static void main(String[] args)
	{
		int len,vis;
		int[] print;
		Integer index;
		sortTree root = new sortTree();
		Scanner input = new Scanner(System.in);
		
		len = input.nextInt();
		vis = input.nextInt();
		for(int i = 0 ; i < len ; i ++)
		{
			int val;
			val = input.nextInt();
			root.insert(val);
		}
		for(int i = 0 ; i < vis ; i ++)
		{
			int del;
			print = new int[20];
			index = 0;
			del = input.nextInt();
			if(root.delete(del) == true){
				System.out.printf("Cut %d\n", del);
			}
			else {
				System.out.printf("Already cut %d\n", del);
			}
			index = root.search(print, index);
			for(int j = 0 ; j < index ; j ++)
			{
				System.out.printf("%d", print[j]);
				if(j + 1 < index){
					System.out.printf(" ");
				}
			}
			System.out.printf("\n");
		}
	}
}
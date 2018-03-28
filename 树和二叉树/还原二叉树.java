import java.util.*;

class tree
{
	char data;
	tree lc = null,rc = null;
	static tree xhuifu(char[] xian,char[] zhong,int xstart,int zstart,int xend,int zend)
	{
		int i;
		tree node;
		
		if(xstart >= xend || zstart >= zend){
			return null;
		}
		node = new tree();
		node.data = xian[xstart];
		for(i = zstart ; zhong[i] != xian[xstart] ; i ++);
		i -= zstart;
		node.lc = xhuifu(xian,zhong,xstart + 1,zstart,xstart + i + 1,zstart + i);
		node.rc = xhuifu(xian,zhong,xstart + 1 + i,zstart + i + 1,xend,zend);
		return node;
	}
	static tree hhuifu(char[] hou,char[] zhong,int hstart,int zstart,int hend,int zend)
	{
		int i;
		tree node;
		if(hstart >= hend || zstart >= zend){
			return null;
		}
		node = new tree();
		node.data = hou[hend - 1];
		for(i = zend - 1 ; zhong[i] != hou[hend - 1] ; i --);
		i -= zstart;
		node.lc = hhuifu(hou,zhong,hstart,zstart,hstart + i,zstart + i);
		node.rc = hhuifu(hou,zhong,hstart + i,zstart + i + 1,hend - 1,zend);
		return node;
	}
	static int getHeight(tree root)
	{
		int lh,rh;
		if(root == null){
			return 0;
		}
		lh = getHeight(root.lc);
		rh = getHeight(root.rc);
		return lh > rh ? lh + 1 : rh + 1;
	}
}
public class Main
{
	public static void main(String[] args)
	{
		String hou,zhong;
		Scanner input = new Scanner(System.in);
		int time;
		time = input.nextInt();
		for(int t = 0 ; t < time ; t ++)
		{
			tree root;
			zhong = input.next();
			hou = input.next();
			root = tree.hhuifu(hou.toCharArray(), zhong.toCharArray(), 0, 0,hou.toCharArray().length , zhong.toCharArray().length);
			System.out.printf("%d\n",tree.getHeight(root));
		}
		input.close();
	}
}
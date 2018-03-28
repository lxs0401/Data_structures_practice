import java.util.*;

class linetree
{
	int l,r;
	int val;
	int lazy;
	linetree lc = null,rc = null;
	
	public void updata(int lazyVal)
	{
		val += (r - l + 1) * lazyVal;
		lazy += lazyVal;
	}
	private void pushDown()
	{
		
		if(lazy == 0){
			return ;
		}
		if(lc != null){
			lc.updata(lazy);
		}
		if(rc != null){
			rc.updata(lazy);
		}
		lazy = 0;
	}
	private void pushUp(){
		val = lc.val + rc.val;
	}
	public void add(int x,int y,int val)
	{
		
		int mid = (l + r)/2;
		if(x <= l && y >= r){
			updata(val);
		}
		else 
		{
			pushDown();
			if(x <= mid) {
				lc.add(x, y, val);
			}
			if(y > mid){
				rc.add(x, y, val);
			}
			pushUp();
		}
	}
	public int search(int x,int y)
	{
		int mid = (l + r)/2;
		
		if(x <= l && r <= y){
			return val;
		}
		else 
		{
			int ans = 0;
			pushDown();
			if(x <= mid) {
				ans += lc.search(x,y);
			}
			if(y > mid){
				ans += rc.search(x,y);
			}
			return ans;
		}
	}
	public void build(int x,int y)
	{
		int mid = (x + y)/2;
		
		val = 0;
		lazy = 0;
		l = x;
		r = y;
		if(x >= y){
			;
		}
		else 
		{
			lc = new linetree();
			rc = new linetree();
			lc.build( x, mid);
			rc.build( mid + 1 , y);
		}
		return ;
	}

}
public class Main
{
	public static void main(String[] args)
	{
		linetree root = new linetree();
		int len;
		int l,r;
		Scanner input = new Scanner(System.in);
		
		len = input.nextInt();
		root.build(0, len - 1);
		for(int i = 0 ; i < len ; i ++)
		{
			int val = input.nextInt();
			root.add(i, i, val);
		}
		l = input.nextInt();
		r = input.nextInt();
		System.out.printf("%d", root.search(l - 1, r - 1));
	}
}
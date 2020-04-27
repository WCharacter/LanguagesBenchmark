import java.util.ArrayList;

public class Test{
	public static void main(String[] args){
		long total = 0;
		int tests_amount = 10;
		int arr_size = 10000000;
		
		for(int k = 0; k < tests_amount; ++k){
			long start = System.currentTimeMillis();
			double sum = 0;
			ArrayList<test_object> lst = new ArrayList<test_object>(arr_size);		
			for(Integer i = 0; i < arr_size; ++i){
				test_object ob = new test_object();
				ob.name = i.toString();
				ob.amount = (double)i;
				lst.add(ob);
			}
			
			for(test_object t_obj : lst){
				sum += t_obj.amount;
			}
			
			System.out.println(sum);
			
			long end = System.currentTimeMillis();
			long elapsed = end - start;
			total += elapsed;
			System.out.println("Elapsed: " + elapsed + " ms.");
		}
		double mean = (double)total / tests_amount; 
		System.out.println("Mean " + mean + " ms.");
	}
}
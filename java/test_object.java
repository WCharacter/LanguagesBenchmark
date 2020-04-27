
public class test_object{
	public String name;
	public double amount;
	
	public String toString(){
		return String.format("(%s,%.14f)", name, amount); 
	}
}
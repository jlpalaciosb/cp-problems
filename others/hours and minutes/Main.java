import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<Object, Object> diccionario = new HashMap<>();
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		for (int i = 0; i<N ; i++) {
			HashMap<Object, Object> aux = diccionario;
			String word = scan.next();
			for (int j = 0; j<word.length(); j++ ) {
				if(aux.containsKey(word.charAt(j))){
					aux = (HashMap)aux.get(word.charAt(j));
				}else{
					aux.put(word.charAt(j), new HashMap<Object,Object>());
				}
			}
		}
		int sum = sumWords(diccionario, 0);
		System.out.println(sum);
	}
	static int sumWords(HashMap<Object, Object> hash, int sumLocal){
		int sum = 0;
		if(hash.size() > 1){
			sumLocal++;
		}
		if(hash.size() == 0){
			sum += sumLocal;
		}
		
		for(Iterator it = hash.keySet().iterator(); it.hasNext();){
			sum += sumWords((HashMap)hash.get(it.next()), sumLocal);
		}
		return sum;
	}
}

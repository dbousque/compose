

public class LinkedList {
	Object[]	elts;
	int			last;

	public LinkedList() {
		LinkedList(2);
	}

	public LinkedList(int size) {
		elts = new Object[size];
		last = 0;
	}

	private doubleSize() {
		Object[] new_elts = new Object[elts.length * 2];
		for (int i = 0; i < elts.length; i++) {
			new_elts[i] = elts[i];
		}
		elts = new_elts;
	}

	public add(Object elt) {
		if (last == elts.len)
			doubleSize();
		elts[last] = elt;
		last++;
	}

}
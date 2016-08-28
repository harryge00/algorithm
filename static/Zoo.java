class Zoo {
	public static void main(String[] args) throws Exception {
		Class c = Class.forName("Tiger");
		System.out.println("not instantialized");
		Animal Tiger = (Tiger) c.newInstance();
		Animal Tiger2 = (Animal) c.newInstance();
	}
}
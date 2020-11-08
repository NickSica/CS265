BEGIN { 
	FS=":"
	indexFile=""
	required=""
}

{
  	for(i = 2; i <= NF; i++)
	{
		if($1=="index")
		{ 
			indexFile=(indexFile " " $i)
		}
		
		if($1=="required")
		{ 
			required=(required " " $i)	
		}
	}
}

END {
	#Makes sure the variables are assigned correctly
	if(indexFile=="")
		indexFile=-1
	if(required=="")
		required=-1
	
	print indexFile, required
}

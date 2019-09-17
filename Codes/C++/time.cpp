#ifdef IDE
	int nol_cl = clock();
#endif

#ifdef IDE
	printf("\nTime: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif

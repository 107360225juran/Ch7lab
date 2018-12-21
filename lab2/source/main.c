#include<stdio.h>
#include<stdlib.h>
struct clientData
{
	int accNum;
	char lasName[15];
	char firstName[10];
	double balance;
};
main()
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0,i,j,k;
	struct clientData client = { 0, "", "",0.0 };

	i = fopen_s(&pRead,"C://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}
	j= fopen_s(&pWrite,"C://credit_bin.txt", "wb");
	if (NULL == pRead)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead,"%d",&client.accNum);
		fscanf_s(pRead,"%s",client.lasName,15);
		fscanf_s(pRead,"%s",client.firstName,10);
		fscanf_s(pRead,"%lf",&client.balance);
		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lasName
			, client.firstName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("以讀取文字檔的ACSII資料，並轉存成二進位資料檔案\n\n");
	system("pause");
	printf("\n讀取二禁制資料檔案，並格式化輸出如下:\n");
	if ((k = fopen_s(&cfPtr,"c://credit_bin.txt", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6d%-16s%-11s%10.2f\n", "Acct", "lasName", "firstName", "balance");
		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		while (cnt > 0)
		{
			printf("%d", cnt);
			printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lasName
				, client.firstName, client.balance);
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
			
		}
		fclose(cfPtr);
	}
	system("pause");
}
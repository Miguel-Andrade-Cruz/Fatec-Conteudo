from django.shortcuts import render


def records(request):
    
    return render(request, "records.html")
from django.shortcuts import render

# from .middleware import format_acc_chart
# from .models import Facts


# def home(request):

#     qs_records = Facts.objects.all().values()
#     records = format_acc_chart(qs_records)

#     return render(request, "home.html", context={"facts": records})


# def form(request):

#     if request.method == "POST":

#         form = FactForm(request.POST)
#         if form.is_valid():
#             data = form.cleaned_data

#     else:
#         form = FactForm()

#     return render(request, "form.html", {"form": form})

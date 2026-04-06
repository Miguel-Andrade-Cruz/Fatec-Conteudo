from django.shortcuts import redirect, render

from .forms import ChartForm
from .middleware import group_records, handle_form_data
from .models import Chart


def home(request):

    qs_records = Chart.objects \
        .select_related("acc", "segm", "niche") \
        .order_by('acc__id', 'segm__id', 'niche__id') \
        .values()

    records = group_records(qs_records)
    return render(request, "home.html", context={"acc_chart": records})


def form(request):

    if request.method == "POST":

        form = ChartForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data
            (account, segment, niche) = handle_form_data(data)

            new_chart = Chart(acc=account, segm=segment, niche=niche)
            new_chart.save()
            return redirect('chart:home')
    else:
        form = ChartForm()
    return render(request, "form.html", context={"form": form})



def testing_show_chart_codes(request):

    qs_records = AccPlan.objects.all()
    return render(request, "testing_show_chart.html", context={"accs": qs_records})

def testing_form_chart(request):

    if request.method == "POST":
        form = AccPlanForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data
            new_acc = AccPlan(label=data["label"])
            new_acc.save()
            return redirect('acc_chart:testing_chart')
    else:
        form = AccPlanForm()

    return render(request, "form_testing_chart.html", context={"form": form})

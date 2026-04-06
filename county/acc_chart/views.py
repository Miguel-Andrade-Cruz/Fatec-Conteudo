from django.shortcuts import render

from .middleware import group_records
from .models import AccChart


def home(request):

    qs_records = AccChart.objects \
        .select_related("acc", "segm", "niche") \
        .order_by('acc__code', 'segm__code', 'niche__code') \
        .values() \
        .exclude("acc__id", "segm__id", "niche__id")

    records = group_records(qs_records)
    return render(request, "home.html", context={"acc_chart": records})


def form(request):

    if request.method == "POST":

        form = AccChartForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data

    else:
        form = AccChartForm()
    return render(request, "form.html", context={"form": form})

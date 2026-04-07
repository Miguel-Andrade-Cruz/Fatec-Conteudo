from django.shortcuts import redirect, render

from .forms import AccountForm, NicheForm, SegmentForm
from .middleware import get_or_new_acc, get_or_new_segm, group_records, pull_segments
from .models import Account, Chart, Niche, Segment


def home(request):

    qs_records = Chart.objects \
        .select_related("acc", "segm", "niche") \
        .order_by('acc__code', 'segm__code', 'niche__code') \
        .values()

    records = group_records(qs_records)
    return render(request, "home.html", context={"acc_chart": records})


def form(request):

    return redirect('chart:acc_form')



def acc_form(request):

    if request.method == 'POST':

        form = AccountForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data

            (info, is_new) = get_or_new_acc(data)
            request.session["acc"] = {"info": info, "is_new": is_new}
            return redirect('chart:segm_form')

    else:
        form = AccountForm()
    return render(request, "forms/acc_form.html", context={"form": form})



def segm_form(request):

    if request.method == 'POST':

        form = SegmentForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data

            (info, is_new) = get_or_new_segm(data)
            request.session["segm"] = {"info": info, "is_new": is_new}
            return redirect('chart:niche_form')

    else:
        form = SegmentForm()
        form.CHOICES = pull_segments(request.session["acc"])
    return render(request, 'forms/segm_form.html', context={"form": form})



def niche_form(request):

    if request.method == 'POST':

        form = NicheForm(request.POST)
        if form.is_valid():
            data = form.cleaned_data

            acc_is_new = request.session.get("acc")["is_new"]
            acc_info = request.session.get("acc")["info"]
            if not acc_is_new:
                acc_obj = Account.objects.get(pk=acc_info)
            else:
                acc_obj = Account(label=acc_info)
                acc_obj.save()


            segm_is_new = request.session.get("segm")["is_new"]
            segm_info = request.session.get("segm")["info"]
            if not segm_is_new:
                segm_obj = Segment.objects.get(pk=segm_info)
            else:
                segm_obj = Segment(label=segm_info)
                segm_obj.save()

            request.session.pop("acc", {})
            request.session.pop("segm", {})

            niche_obj = Niche(label=data["new_niche"])
            niche_obj.save()

            chart_obj = Chart(acc=acc_obj, segm=segm_obj, niche=niche_obj)
            chart_obj.save()
            return redirect('chart:home')
    else:
        form = NicheForm()
    return render(request, 'forms/niche_form.html', context={"form": form})




# def testing_show_chart_codes(request):

#     qs_records = AccPlan.objects.all()
#     return render(request, "testing_show_chart.html", context={"accs": qs_records})

# def testing_form_chart(request):

#     if request.method == "POST":
#         form = AccPlanForm(request.POST)
#         if form.is_valid():
#             data = form.cleaned_data
#             new_acc = AccPlan(label=data["label"])
#             new_acc.save()
#             return redirect('acc_chart:testing_chart')
#     else:
#         form = AccPlanForm()

#     return render(request, "form_testing_chart.html", context={"form": form})
